# DIVA Loader

**DIVA Loader** lets you load plugins into **Hatsune Miku Project DIVA Arcade Future Tone** by placing them into the **"plugins"** folder, it includes useful ones such as **TLAC** by **Samyuu** and **Prepatch** in the form of a plugin without needing to use extra executables.

## Installation

* Have a **full clean** dump of the game version **"7.10"** decompressed without **"mdata"** merges or any other modifications.
* Download the latest release.
* Decompress everything into the **root folder** of the game.
* Files required to load **"mdata"** without merging it into the actual game are included (**"ram\databank\PvList*"** files, up to **M270** is supported.).

For this to work, you have to drop each **mdata** update decompressed into the folder **"mdata\"** (create it if it doesn't exists).

**e.g.** For all **"mdata"** you should have the following folders inside:
  * M215
  * M220
  * M230
  * M240
  * M250
  * M260
  * M270

## Usage

Use the **"plugins\config.ini"** to enable or disable plugins loading.

Place any **Dynamic-link library (DLL)** with the filename extension as **".dva"** inside the **"plugins"** folder.\
**TLAC v2.0** and an alternative for **"Prepatch"** are included by default.

Just launch **"diva.exe"** with your desired parameters (e.g. **"-w -hdtv1080"**).

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)

## FAQ

**"Prepatch"** is not needed, it works with the original game executable. Special thanks to **Skyth**.

Special thanks to korenkonder for **"PvList"**.

Configuration files for **TLAC** and any other compatible extension will be read from **"plugins\"** and **NOT** from the root folder of the game.

This is a stripdown of [**ThirteenAG's** Ultimate ASI Loader v4.47](https://github.com/ThirteenAG/Ultimate-ASI-Loader/) for **"dinput8.dll"** usage only with minor modifications.

[TLAC (TotallyLegitArcadeController) v2.0](https://github.com/samyuu/TotallyLegitArcadeController) by **Samyuu**.

Solution for **Visual Studio 2019** platform toolset **v142** and **Windows 10 SDK (10.0.17763.0)**.

Requires **Windows Universal CRT SDK**.
