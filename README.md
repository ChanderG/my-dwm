#What?

[dwm](http://dwm.suckless.org/) aka dynamic window manager is a tiling window manager. It does get some time to get used to. It is fully customizable and here are my tweaks.

###How to tweak?

Just edit the "config.h" file. Save and

```
sudo make clean install
```

###A notification panel
One thing you miss sorely in dwm is a notification panel. Rather than creating one (which is invariably going to be only static), you can use gnome-panel with dwm by setting its float value correctly.

Also added the keybinding MOD+g to open gnome-panel. Just add the following lines:

```
static const char *gpcmd[]  = { "gnome-panel", NULL };

//later add this row in the keys section
{ MODKEY,                       XK_g,      spawn,          {.v = gpcmd } },
```

###Anything you need is a few keys away

I almost always need Firefox. So,

```
static const char *ffcmd[]  = { "firefox", NULL };

//later add this row in the keys section
{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = ffcmd } },
```

You get the idea. Just make sure no key binding clashes occur.

###Suspend with lock
Putting the computer in sleep mode is essential for me. However it needs to come with screen locking for safety. Here is my hack for this need. 

For putting to sleep, I am using "pm-utils". For screenlock "slock" from suckless.

Create a bash script as follows:
```
sudo pm-suspend ; slock
```
and put it in /usr/local/bin.

You should be able to see the script in dmenu.You can also map it to some keys as done before.

However there is a catch. As it stands we need to enter password for sudo which cannot be done as the command is not being execute in a terminal. The workaround is to add an entry in the sudoers file.

[Source](http://sohcahtoa.org.uk/pages/linux-dwm-window-manager-on-debian.html) for some of my info.

Open the file using:
```
sudo visudo
```

Don't let the name fool you, the editor is not vi/vim, it is nano.
Add an entry as given in the linked article or google. In the command alias section create an alias to /usr/sbin/pm-suspend.

Also, when you wake the computer from sleep, the screen is shown for a couple of seconds after which the slock kicks in. Also if you are using slock, there is no prompt for a password. It is just a black screen that turn blue as you start typing your password.

###Wishlist or TODO

* Remap terminal to some easy key (say Windows/Command).
* Remap dmenu to the menu key. 
* Both the above depends on getting the X key code for the respective keys.
* Getter a better solution to the sleeplock hack.
* In general organize keybindings for applications vs dwm-related stuff.
* Use xterm + tabbed as follows:
```
tabbed -c xterm intro 
```
Modify dwm keybindings, tabbed key bindings to shadow gnome-defaults.

###See also
My original [source](http://holymonkey.com/dwm-with-gnome-guide.html) of the gnome-panel idea.
The keybindings [source](http://srobb.net/dwm.html).
