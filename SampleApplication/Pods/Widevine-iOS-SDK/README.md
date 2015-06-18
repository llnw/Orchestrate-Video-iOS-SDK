Widevine SDK
============

This repository contains the necessary bits to declare a versioned dependency on
the Widevine SDK using [CocoaPods](http://cocoapods.org/).  It is not like the
[Specs](https://github.com/CocoaPods/Specs) library from the CocoaPods
project (more on that below). This repository would be where the source code would be housed if it
were available. Instead, we check in the binary and header file provided by
Widevine, as well as a stub implementation. The stub implementation is included
so that projects that link to the Widevine SDK will still be able to run on the
simulator. Widevine intentionally did not compile symbols in for
i386 into their library for security reasons.

Creating a Specs Repository
---------------------------

In order to have this library installed correctly, you must add the
[PodSpecs](https://github.llnw.net/llnw/PodSpecs) repository to your
local machine. Assuming you have installed CocoaPods, then simply run `pod repo
add PodSpecs git@github.llnw.net:llnw/PodSpecs.git`. Once complete,
you have the Specs repository from the CocoaPods project, as well as the
PodSpecs repository internal to Limelight Networks.

A Note About Versioning
-----------------------

Widevine has not been consistent in their versioning and artifact naming
conventions. Below is a table showing the mapping used here.

| Tagged Version | Widevine Artifact Version |
|----------------|---------------------------|
| 6.0.0.12556    | 6.0.0.402.12556           |
| 6.0.0.12564    | 6.0.0.12564               |

Getting Help
------------

If you have any questions, don't hesitate to contact
[dthompson](mailto:dthompson@llnw.com).
