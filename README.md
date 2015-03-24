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

###See also
My original [source](http://holymonkey.com/dwm-with-gnome-guide.html) of the gnome-panel idea.
The keybindings [source](http://srobb.net/dwm.html).
