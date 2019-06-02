# DIVA Loader

**DIVA Loader** lets you load plugins into **Hatsune Miku Project DIVA Arcade Future Tone** by placing them into the **"plugins"** folder, it includes useful ones such as **TLAC** and **Prepatch** by **Samyuu** in the form of a plugin without needing to use extra executables.

## Installation

* Have a **full clean** dump of the game version **"7.10"** decompressed without **"mdata"** merges or any other modifications.
* Download the latest release.
* Decompress everything into the **root folder** of the game.

* **"mdata"** from **M215** to **M270** are supported, custom **"mdata"** will be possible soon.
* Files required to load **"mdata"** without merging it into the actual game are included (**"ram\databank\PvList*"** files)

For **"mdata"** to work, you have to drop each **"mdata"** update decompressed into the **"mdata\"** folder in the root folder of the game (create it if it doesn't exists).

**e.g.** For all **"mdata"** you should have the following folders inside:
  * M215
  * M220
  * M230
  * M240
  * M250
  * M260
  * M270

## Usage

Use **"plugins\components.ini"** to enable or disable TLAC components.\
Use **"plugins\config.ini"** to enable or disable plugins loading along other useful settings.\
Use **"plugins\keyconfig.ini"** to change your game keybinds.\
Use **"plugins\playerdata.ini"** to change your playername and other player customization.

Place any **Dynamic-link library (DLL)** with the filename extension as **".dva"** inside the **"plugins"** folder.\
**TLAC v2.0** and an alternative for **"Prepatch"** are included by default.

Launch **"diva.exe"** with **"-w"** to be able to use a custom windowed size, otherwise it will be always the size of the desktop.\
Launch **"diva.exe"** with **"-wqhd"** to be able to use a custom internal resolution.\

## Screenshots

Your **root** game folder should look like this:

![root game folder](https://i.imgur.com/D48bJS0.png)

Your **"mdata"** folder should look like this:

![mdata folder](https://i.imgur.com/2jUjosM.png)

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)

## FAQ

Compatible with **Windows 7** except for WMV PV videos.

Previous versions used **dinput8.dll** in the game root folder, if you still have it you must delete it.

**"Prepatch"** is not needed, it works with the original game executable. Special thanks to **Skyth**.

Special thanks to **korenkonder** for **"PvList"**.

Configuration files for **TLAC** and any other compatible extension will be read from **"plugins\"** and **NOT** from the root folder of the game.

This is a stripdown of [**ThirteenAG's** Ultimate ASI Loader v4.47](https://github.com/ThirteenAG/Ultimate-ASI-Loader/) for **"dinput8.dll"** usage only with minor modifications.

[TLAC (TotallyLegitArcadeController) v2.0](https://github.com/samyuu/TotallyLegitArcadeController) by **Samyuu**.

Solution for **Visual Studio 2019** platform toolset **v142** and **Windows 10 SDK (10.0.17763.0)**.

Requires **Windows Universal CRT SDK**.
