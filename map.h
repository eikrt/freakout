#ifndef MAP_H 
#define MAP_H
static const char levels[][20*16*8] = {
        {
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ',' ',
    ' ',' ',' ','x','x','x','x','x','e','e','e','e','x','x','x','x','x','x','x',' ',
    ' ',' ','x','x','x','x','x','x','x','e','e','x','x','x','x','x','x','x','x',' ',
    ' ',' ','x','x','x','x','x','x','x','e','e','x','x','x','x','x','x','x','x',' ',
    ' ',' ','x','x','x','x','t','t','x','e','e','x','t','t','x','x','x','x',' ',' ',
    ' ',' ','x','x','x','x','x','x','x','e','e','x','x','x','x','x','x','x',' ',' ',
    ' ',' ',' ','x','x','x','x','x','e','e','e','e','x','x','x','x','x',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x','x','x','x','x','x','x','x','x','x',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ','x','x','x','x','x','x','x','x','x',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ','x','x','i','x',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',

    },
        {
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x',' ',' ',' ',
    ' ',' ',' ',' ','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x',' ',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x','x','x','x','x','x','x','x','x','x',' ',' ',' ',' ',
    ' ',' ',' ','x','x','x','x','x','e','e','e','e','x','x','x','x','x',' ',' ',' ',
    ' ',' ','x','x','I','x','x','x','x','x','x','x','x','x','x','I','x','x',' ',' ',
    ' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ','x',' ',
    ' ','x','x','t','x','x','x','x','e','e','e','e','x','x','x','x','t','x','x',' ',
    ' ','x',' ','t','t','x','x','x','x','x','x','x','x','x','x','t','t',' ','x',' ',
    ' ','x',' ','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','t',' ','x',' ',
    ' ',' ',' ',' ','t','t',' ',' ',' ',' ',' ',' ',' ',' ','t','t',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',

    },
        {
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ','i','i','i','i',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ','i',' ',' ','i','x','x','i',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ','t','i','i','x','e','x','x','i',' ',' ','I','I','I',' ',' ',
    ' ',' ',' ',' ',' ','t','t','x','x','e','x','x','x',' ',' ','x','e','x',' ',' ',
    ' ',' ',' ',' ',' ','t','t','t','e','e','e','x','x',' ',' ','i','i','i',' ',' ',
    ' ',' ',' ',' ',' ','t','t','t','e','e','e','x','x',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ','t','t','t','t','t','x','x','x',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ','x','x','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ','e','e','e',' ',' ','x','x','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ','x','x','x',' ',' ',' ','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',

    },
        {
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ',' ',
    ' ',' ',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ',' ',
    ' ',' ',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ',' ',
    ' ',' ',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ',' ',
    ' ',' ',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ',' ',
    ' ',' ',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ','x','x','x',' ',' ',' ',
    ' ',' ',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ','x',' ','x',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',

    },
        {
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','I','I',' ',' ',' ',' ',' ',' ',
    ' ','t','t','t',' ',' ',' ','i','i','i',' ','I','I','I','I',' ',' ',' ',' ',' ',
    ' ','t','t','t','t','t','i','e','e','e','i',' ','I','I',' ',' ',' ',' ',' ',' ',
    ' ','t','t','t',' ',' ',' ','i','i','i',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ','t',' ',' ',' ',' ',' ',' ',' ',' ',' ','x',' ',' ','x',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x','x','x','x','x',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x','x','x','x','x','x','x',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x','x','x','x',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x','x','x','x',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x',' ','x',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','x',' ','x',' ',' ',' ',' ',' ',' ',

    },
        {
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ','x','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ','x',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x',' ',' ',' ',' ',' ',' ',' ','x',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x','x',' ',' ',' ',' ',' ',' ','x',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ','x','x','x','x','x',' ',' ',' ','x','x',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ','x','e','x','x','x','x',' ','x','x',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ','x','x','x','e','x','x','x','x','x','x',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ','x','x','x','x','e','e','e','x','x','x','x',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ','x','x','x','x','x','x','x','x','x','x','x','x',' ',' ',' ',
    ' ',' ',' ',' ',' ','x',' ',' ','x',' ',' ','x','x','x','x','x','x','x','x','x',
    ' ',' ',' ',' ',' ','x',' ',' ','x',' ',' ',' ','x',' ',' ','x',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',

    },
        {
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ','t','t','t','x','x','x','x','x','x','x','x','x','x','x','x','t','t','t',' ',
    ' ','t','e','x','x','x','x','x','x','x','x','x','x','x','x','x','x','e','t',' ',
    ' ','t','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','t',' ',
    ' ','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t',' ',
    ' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ',
    ' ','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t',' ',
    ' ','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x','x',' ',
    ' ','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t','t',' ',
    ' ','t','e','x','x','x','x','x','x','x','x','x','x','x','x','x','x','e','t',' ',
    ' ','t','t','t','x','x','x','x','x','x','x','x','x','x','x','x','t','t','t',' ',
    ' ','i','i','i','i','i','i','i','i','i','i','i','i','i','i','i','i','i','i',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',

    },
        {
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ','i','i','i','i','i',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ','i','t','t','t','i','t',' ',' ',' ',' ',' ',' ','i',' ',' ',' ',' ',
    ' ',' ',' ','i','t','x','t','i',' ','t','t','t','t','t','t',' ','e','e','e',' ',
    'e','e',' ','i','t','t','t','t','t','t','t','t',' ',' ',' ','i',' ',' ',' ',' ',
    ' ',' ',' ','i','t','t','t','i',' ','t','t','t',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ','i','t','t','t','i',' ','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ','i','t','t','t','i',' ','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ','i','t','t','t','i',' ','t',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ','i','i','i','i','i',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ','x','x','x',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',

    },
        {
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',

    }
};
static const char levelNames[32][32] = {"Zeppelin", "Paranoid A", "El", "Heaven", "Abduction?", "Mach", "McBrick", "Noir", ""};
#endif
