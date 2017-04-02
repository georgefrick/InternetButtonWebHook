# InternetButtonWebHook
This is a simple web hook using the Particle Internet Button. It will currently do a HTTP POST to a Discord Bot to play a sound effect in the specified users channel. (It's a GG Button)

# Setup

## Button
If you want to recreate this, you'll need an internet button, setup and claimed by a spark account. Start here:
https://store.particle.io/collections/shields-and-kits

## Code
The code is provided in this repository. For the two libraries you'll need to go to libraries in the web editor and
add them both. Make sure the include doesn't end up doubled-up.

## Web Hook
This webhook hits a Discord Bot, but you could hit anything. If you want to setup the Discord bot, start here:
https://github.com/Darkside138/DiscordSoundboard

## Customize
You could make it play different sounds for different buttons, etc. Make sure to change the soundFileId to one loaded on your server, and the username should be the person to find and play the sound for.

## Serial Output
To use the Serial output, have your internet button connected via usb and type 'particle serial monitor'.

## Soundboard API
If you setup the Discord Sound Board from Darkside, you can hit /v2/api-docs to see the full available api. For example: http://localhost:8080/v2/api-docs

