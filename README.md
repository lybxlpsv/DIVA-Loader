# DIVA Loader

**DIVA Loader** lets you load plugins into **Hatsune Miku Project DIVA Arcade Future Tone** by placing them into a **"plugins"** folder, it includes useful ones such as **TLAC** and a **Launcher** in the form of a plugin without needing to use extra executables.

## Legal

The code included in this repository is intended for the solely usage of investigative reasons for the **Hatsune Miku Project DIVA Arcade Future Tone** videogame.\
Based on your current jurisdiction, it may be illegal to use this software.\
Additionally a [MIT License](https://github.com/Rayduxz/DIVA-Loader/blob/master/LICENSE) is provided.

## Installation

* Have a **full clean** game version **"7.10"** decompressed without any modifications to prevent compatibility issues.
* Download the latest release of **DIVA Loader**.
* Decompress everything into the **root folder** of the game.

* Install the official **"mdata"**.
**M215** to **M270** are supported, custom ones are also supported.

To install them you have to drop each **"mdata"** update decompressed into the **"mdata\"** folder in the root folder of the game (create it if it doesn't exists).

**e.g.** For all the official **"mdata"** you should have the following folders inside:
  * M215
  * M220
  * M230
  * M240
  * M250
  * M260
  * M270

Files required to make **"mdata"** available in the game are included (**"ram\databank\PvList*"** files).

## Usage

**IMPORTANT:** Do *not* edit any of the *.ini* configuration files with Notepad. Use [Notepad++](https://notepad-plus-plus.org/download) (or WordPad) with UTF-8 encoding instead, otherwise your game may crash.

Use **"plugins\components.ini"** to enable or disable TLAC components.\
Use **"plugins\config.ini"** to enable or disable plugins loading along other useful settings.\
Use **"plugins\keyconfig.ini"** to change your game keybinds.\
Use **"plugins\playerdata.ini"** to change your playername and other player customization.

Place any **.dva** plugin you want to use inside the **"plugins"** folder.\
**TLAC** with community modifications and a **"Launcher"** along other useful plugins are included by default.

Launch **"diva.exe"**.
Use **"--launch"** argument to bypass the launcher and to be able to use other arguments.

## Screenshots

Your **root** game folder should look like this:

![root game folder](https://i.imgur.com/c57lQPH.png)

Your **"mdata"** folder should look like this:

![mdata folder](https://i.imgur.com/2jUjosM.png)

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)

## Third party plugins

[DiscordDiva](https://github.com/bela333/DiscordDiva) - Discord integration for game version **7.10** by **bela333**.\
[DivaSound](https://github.com/somewhatlurker/DivaSound) - Replacement audio output for game version **7.10** by **somewhatlurker**, this plugin is a must if you have audio issues or no audio at all.

## FAQ

Only **NVIDIA** videocards are supported for now, [AMD and Intel GPU support](https://github.com/Rayduxz/DIVA-Loader/issues/8) are possible but further research needs to be done.

**Linux** can run the game with **Wine**, for audio you must use [DivaSound](https://github.com/somewhatlurker/DivaSound).\
WMV movie videos are not supported and it is recommended to set **No_Movies** to **1** to prevent crashes when the game attempts to load a movie.

**Windows 7** is supported except for [WMV movie videos](https://github.com/Rayduxz/DIVA-Loader/issues/15).

Previous versions used **dinput8.dll** in the game root folder, if you still have it you must delete it.

Always use the original game executable.

[TLAC (TotallyLegitArcadeController) v2.0](https://github.com/samyuu/TotallyLegitArcadeController) by **Samyuu**.

Special thanks to **Brolijah**, **Skyth**, **korenkonder**, **Samyuu**, **somewhatlurker**, **Cainan**, **crash5band**, **vladkorotnev**, **lybxlpsv** and everyone else who helped at the [Project DIVA Modding 2nd Community Discord](https://discord.gg/cvBVGDZ), come join us if you want to help us to improve this project.

## Developer FAQ

To enable logs and dumps create a folder called "logs" in the root folder, each dump size is 200MB so watch your disk space.

This is a stripdown of [**ThirteenAG's** Ultimate ASI Loader v4.47](https://github.com/ThirteenAG/Ultimate-ASI-Loader/) for **"dnsapi.dll"** usage only.

Solution for **Visual Studio 2019**.\
Requires platform toolset **v142**.\
Requires **Windows 10 SDK (10.0.17763.0)**.

Requires **Desktop development with C++**.\
Requires **Windows Universal CRT SDK**.

Requires **.NET desktop development** (Launcher plugin).\
Requires **.NET Framework 4 targeting pack** (Launcher plugin).\
Requires **C++/CLI support for v142 build tools (14.21)** (Launcher plugin)

Requires [**Microsoft Research Detours Package**](https://github.com/microsoft/Detours) (included in the solution).\
Requires [**FreeGLUT 3.0.0 DIVA**](https://github.com/Rayduxz/FreeGLUT) (included in the solution).
