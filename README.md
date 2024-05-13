# valen's dwm
![valen's dwm preview](dwm.png?)

## Patches applied

- alttab/ https://dwm.suckless.org/patches/alt-tab/
- alwayscenter/ https://dwm.suckless.org/patches/alwayscenter/
- attachbottom/ https://dwm.suckless.org/patches/attachbottom/
- ewmhtags/ https://dwm.suckless.org/patches/ewmhtags/
- fakefullscreen/ https://dwm.suckless.org/patches/fakefullscreen/
- focusonclick/ https://dwm.suckless.org/patches/focusonclick/
- focusonnetactive/ https://dwm.suckless.org/patches/focusonnetactive/
- fullscreen/ https://dwm.suckless.org/patches/fullscreen/
- moveresize/ https://dwm.suckless.org/patches/movestack/
- movestack/ https://dwm.suckless.org/patches/movestack/
- notitle/ https://dwm.suckless.org/patches/notitle/
- pertagwithsel/ https://dwm.suckless.org/patches/pertag/
- preserveonrestart/ https://dwm.suckless.org/patches/preserveonrestart/
- rainbowtags/ https://dwm.suckless.org/patches/rainbowtags/
- save floats/ https://dwm.suckless.org/patches/save_floats/
- statuscolors/ https://dwm.suckless.org/patches/statuscolors/
- statuspadding/ https://dwm.suckless.org/patches/statuspadding/
- tilewide/ https://dwm.suckless.org/patches/tilewide/
- vanitygaps/ https://dwm.suckless.org/patches/vanitygaps/
- xresources/ https://dwm.suckless.org/patches/xresources/
- zoomswap/ https://dwm.suckless.org/patches/zoomswap/


## Installation

```bash
git clone https://github.com/valen-gh/dwm-vl.git "$HOME/.local/opt/dwm"
cd "$HOME/.local/opt/dwm"
sudo make install
```


## Useful bash aliases

```bash
alias cdwm="cd $HOME/.local/opt/dwm"
alias sls="rm -f config.h && doas make install && killall dwm"
```

