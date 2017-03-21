#What?

[dwm](http://dwm.suckless.org/) aka dynamic window manager is a tiling window manager. It does get some time to get used to. It is fully customizable and here are my tweaks.

Vendoring dwm for mu ease of use, as it is quite stable anyway. Currently on version 6.1. 6.1 is dependent on dmenu 4.6, meaning you need to upgrade that as well. May vendor dmenu into this repo as well, depending on need.

###How to tweak?

Just edit the "config.h" file. Save and

```
sudo make clean install
```

###Anything you need is a few keys away

I almost always need Firefox. So,

```
static const char *ffcmd[]  = { "firefox", NULL };

//later add this row in the keys section
{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = ffcmd } },
```

You get the idea. Just make sure no key binding clashes occur.

### Terminal(s)

So terminals are something I need aplenty.

Current keybindings:

Alt + Shift + u         -- urxvt 

urxvt with tmux is the only thing I am using these days.

Terminals had a problem of empty spaces around them. This has now been solved.

###Dropdown terminal

See [this](https://github.com/noctuid/tdrop) for an awesome terminal independent drop down setup. I use it with urxvt + tmux, which gives me everything needed.

###Modifiers as independent keys

Also using [xcape](https://github.com/alols/xcape) to overload modifiers. With this setup and the above 2 points, I have awesome control on the system.

Some exceptional things can be done with this. Some combos in my configuration now are:
1. Use Right Alt and Ctrl to Inc/Dec tag. In combination with nextprevtag patch.
2. Use Right Shift directly as Alt|Tab key combination. Once click tag switch.
3. Left Ctrl for dropdown terminal.
4. Left Shift for cycling through windows in current tag.

###Smart Key(s)

With xcape mentioned above, we can go far with shortcuts. However, we can go even further. We can create a context aware smart key. In my case, the Windows key, that is Super.

Start with xcape and bind a free key to an unused dwm key combo. In dwm, map the combo to run a script of your choice. In my setup, look at the `smart-prefix` script. So, far we can run a script with a single command.

Now, fill the script with commands that run based on the current active window. Simple matter of using xdotool to get the title and from there you can have a truly overloaded context aware key.

In my setup, for instance, if the current window is a tmux session, the Super key performs the role of tmux prefix. Else, it opens a new urxvt terminal. Stands to reason that I don't really need a new urxvt terminal if I am using tmux currently. Still, the direct dwm key combination still works if needed.

###Gaps between windows

[Uselessgap](http://dwm.suckless.org/patches/uselessgap) is a dwm patch to insert gaps between windows in tiling mode alone. Currently included.

###Top bar transparency

Using [Alpha](http://dwm.suckless.org/patches/alpha) is a dwm patch to bring in transparency to the top bar. Be warned, this will not work without a separate compositing manager running. I use xcompmgr.

###Per Tag

Have separate layout per tag.

###List of Patches
All included in the source. Listing here for future upgrade requirements.

+ uselessgap - http://dwm.suckless.org/patches/uselessgap
+ alpha - http://dwm.suckless.org/patches/alpha
+ pertag - http://dwm.suckless.org/patches/pertag
+ nextprevtag - http://dwm.suckless.org/patches/nextprevtag

###See also
My original [source](http://holymonkey.com/dwm-with-gnome-guide.html) of the gnome-panel idea.
The keybindings [source](http://srobb.net/dwm.html).
Some tutorials [here](http://forums.debian.net/viewtopic.php?f=16&t=65110) and elsewhere.
