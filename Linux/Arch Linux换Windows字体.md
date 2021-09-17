# Arch Linux换Windows字体

## 第一步：提取

Windows系统的字体位于`C:/Windows/Fonts`  
复制到Linux系统后，将其中后缀为的`.fon`的文件删除，因为没用  

## 第二步：移动

```sh
sudo mv ~/Desktop/Fonts /usr/share/font/winfonts 
```

## 第三步：生效

```sh
sudo pacman -S xorg-mkfontscale
cd /usr/share/winfonts
sudo mkfontscale
sudo mkfontdir
fc-cache -fv
```