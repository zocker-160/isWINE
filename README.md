# isWINE

![WTFPL badge](http://www.wtfpl.net/wp-content/uploads/2012/12/wtfpl-badge-4.png)

isWINE is a very small and simple application and dynamic link library to check if your app is running in a Linux WINE environment.

#### Output on Windows:

```
$> isWINE.exe
0
```
Exit Code: `0`

#### Output on Linux:

```bash
$> wine isWINE.exe
1
7.0
```
Exit Code: `1`

If you get `fixme` errors in the output, you can add `WINEDEBUG=fixme-all` to the command.
