#ifndef RESOURCES_H
#define RESOURCES_H

//função clear
#define start puts("\x1B[H")
#define c puts("\x1B[2J")


//styles
#define bold "\x1B[1m"
#define reset "\x1B[0m"
#define resetBold "\x1B[22m"

//colors
#define black_F "\x1B[30m"
#define resetBlack_F "\x1B[0;30m"
#define red_F "\x1B[31m"
#define green_F "\x1B[32m"
#define yellow_F "\x1B[1;33m"
#define resetYellow_F "\x1B[0;33m"
#define blue_F "\x1B[34m"
#define magenta_F "\x1B[35m"
#define cyan_F "\x1B[36m"
#define white_F "\x1B[37m"
#define default_F "\x1B[39m"

#endif
