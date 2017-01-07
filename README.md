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

###Gaps between windows

[Uselessgap](http://dwm.suckless.org/patches/uselessgap) is a dwm patch to insert gaps between windows in tiling mode alone. Currently included.

###List of Patches
All included in the source. Listing here for future upgrade requirements.

+ uselessgap - http://dwm.suckless.org/patches/uselessgap

###See also
My original [source](http://holymonkey.com/dwm-with-gnome-guide.html) of the gnome-panel idea.
The keybindings [source](http://srobb.net/dwm.html).
Some tutorials [here](http://forums.debian.net/viewtopic.php?f=16&t=65110) and elsewhere.
