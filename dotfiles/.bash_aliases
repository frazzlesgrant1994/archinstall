# Aliases
alias c='clear'
alias ..='cd ..'
alias ls='ls -1'
alias ll='s -lisa --color=auto'
alias mkdir='mkdir -pv'
alias free='free -mt'
alias ps='ps auxf'
alias psgrep='ps aux | grep -v grep | grep -i -e VSZ -e'
alias wget='wget -c'
alias histg='history | grep'
alias myip='curl ipv4.icanhazip.com'
alias grep='grep --color=auto'
alias update='yay -Syu'
alias mkdir="mkdir -pv"
alias install='sudo pacman -S "$@"'
alias remove='sudo pacman -R "$@"'
alias clean='~/.bin/./Arch-maintain.sh'
alias drive='sudo mount -a'
alias tcn='mv --force -t ~/.local/share/Trash '
alias getpass='openssl rand -base64 "$@"'
alias speed='speedtest-cli  --simple'
alias led='g213-led -a "$@"'
alias ping='ping -c 5'
alias :q="exit"
alias ext="exit"
alias xt="exit"
alias by="exit"
alias bye="exit"
alias die="exit"
alias quit="exit"
alias ba="nano ~/.bash_aliases"
alias hide="gnome-extensions disable ding@rastersoft.com"
alias show="gnome-extensions enable ding@rastersoft.com"

