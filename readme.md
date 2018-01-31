# Morrowind Script Extender v2

## Synopsis
The Morrowind Script Extender makes additional functions available for use in Morrowind scripts, beyond those provided by the game's construction set. 

These extra functions allow modders to add features and behavior to scripts that would otherwise be impractical or impossible.

For a list of recent releases, see the [changelog](changelog.md).

## Installation

* Download the latest MWSE release from [GitHub](https://github.com/MWSE/MWSE/releases) and unpack to a temporary directory.
* If you use MGE XE 0.10.0 beta 9 or later:
	* (Optional) Backup `MWSE.dll` in your Morrowind directory.
	* Copy `MWSE.dll` from the archive in step 1 to your Morrowind directory.
	* You can now start Morrowind as before. MGE XE will load the updated `MWSE.dll` on startup.
* If you do not use MGE XE:
	* (Optional) If they exist, backup the following files in your Morrowind directory: `MWSE.dll`, `MWSE Launcher.exe`.
	* Copy `MWSE.dll` and `MWSE Launcher.exe` from the archive in step 1 to your Morrowind directory.
	* To run Morrowind with MWSE enabled, run `MWSE Launcher.exe` and click "Launch Morrowind".
* (Optional) MWEdit
	* (Optional) Backup `customfunctions.dat` in your MWEdit directory.
	* Copy `customfunctions.dat` from the archive in step 1 to your MWEdit directory.
	* MWEdit will now be able to compile scripts that contain MWSE functions.

The [Morrowind Code Patch](https://www.nexusmods.com/morrowind/mods/19510/) is highly recommended.

## Function Reference

See `newfunctions.txt` for functions added since v0.9.4a. This format is temporary and will be converted to something more user-friendly soon.

The [Morrowind Modding Wiki](http://wiki.theassimilationlab.com/mmw/Main_Page) has a [section devoted to MWSE](http://wiki.theassimilationlab.com/mmw/MWSE), containing example scripts and other information.

## Developers
This software is based on the 0.9.5 version of MWSE by Merzasphor, which is in turn based on the 0.9.4a version of MWSE, released by the Sourceforge MWSE Dev Team.

MWSE developers:

- Anthony Garcia
- Charles Cooley (cdcooley)
- Cody Erekson (Fliggerty)
- FreshFish
- Grant McDorman
- Greatness7
- Merzasphor
- Michael Wallar (NullCascade)
- Tim Peters
- Timeslip

### Contributing

The Morrowind Script Extender is open source software that welcomes contributions in the forms of ideas, bug fixes, and new features.

The following features are required through the *Visual Studio 2017* installer:
* Workloads:
	* Desktop development with C++
* Individual components:
	* VC++ 2017 v141 toolset (x86,x64)
	* Windows 10 SDK for Desktop C++ [x86 and x64] (any version will do)

To contribute to the project, clone the source code as a subdirectory of the base Morrowind game directory. Load the MWSE\\MWSE.sln. Functions are organized by category under Source Files\\Functions. The local debugger is configured to automatically attach to Morrowind.exe, so new developers can quickly get on their feet and test functions.

## License
The Morrowind Script Extender is free software, licensed according to the GNU General Public License, and comes with ABSOLUTELY NO WARRANTY. See the file LICENSE.TXT for details if you are interested in distributing or modifying the program.