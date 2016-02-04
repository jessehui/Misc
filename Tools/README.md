#Show/Hide Hidden Files on OSX


OSX is a very good operating system, which is obvious. It provides users with great tidiness and convenience when using it. 
However, people who have some special needs like developing may find it troublesome to find some hidden files. And this article
will talk about the methods to deal with it.


## Using Terminal command
We can simple open Terminal.app and copy and paste this code
```Bash
defaults write com.apple.finder AppleShowAllFiles -boolean true ; killall Finder
```
to show the hidden files and this code
```Bash
defaults write com.apple.finder AppleShowAllFiles -boolean false ; killall Finder
```
to hide them after searching.

## Write a shell script
It will be still troublesome to copy and paste this everytime you need it. So we can just create a shell script file and when we need it, we just double click it. The files are listed in this repository. However, if you just open it with Terminal.app, it will show permission denied and will make no difference. Because the files you created don't have the permission to execute the command. Thus we should change the authority of those two files. 
First we move to the directory of the files. And use
```Bash
chmod -a-x hide.sh
chmod -a-x ShowAll.sh
```
After that, double click the ShowAll.sh file and you can see all hidden files. And when you want your directory to be tidy and clean, just double click the hide.sh file. Simple, huh?
Nevertheless, you may find the white icon ugly, you can download or create your own icons and replace them.

