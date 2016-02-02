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
It will be still troublesome to copy and paste this everytime you need it. So we can just create a shell script file and when we
need it, we just double click it.

