#pragma once

namespace kenny
{
    enum class Part
    {
        PantFront           = 0,
        ArmLeft_Open        = 1,		    
        ArmRight_Open       = 2,
        ArmLeft_Bend        = 3,
        ArmRight_Bend       = 4,
        BadyFront           = 5,
        ArmFrontLeft_Basic  = 6,
        ArmFrontRight_Basic = 7,        
        Face                = 8,
        EyesFront_Open      = 9,
        EyeballLeft         = 10,   
        EyeballRight        = 11,   
        HatFront            = 12,
        HandLeft_Paper      = 13,
        HandRight_Paper     = 14,
        HandLeft_Rock       = 15,
        HandRight_Rock      = 16,
        EyebrowLeft         = 17,
        EyebrowRight        = 18,

        PartNumber          = 19
    };

    enum class Sheetsize : int
    {
        x = 1710,
        y = 1018
    };

    
    struct Vec2
    {
        int x;
        int y;
    };

    struct DirX
    {
        int right;
        int left;
    };
    
    struct Style
    {
        int eyes;
        bool eyebrow;
        DirX arm;
        DirX hand;
    };

    struct KennyTexData
    {
        Vec2 size;
        Vec2 sheetPos;
        Vec2 basicPos;
    };
    
    const KennyTexData g_TexData[] = {
        450, 250,   1260,  122,        0, -325,     //PantFront             
        250, 150,    250,    0,      263, -197,     //ArmLeft_Open       
        250, 150,      0,    0,     -251, -201,     //ArmRight_Open      
        200, 300,   1450,  418,      221, -231,     //ArmLeft_Bend       
        200, 300,   1450,  718,     -207, -233,     //ArmRight_Bend      
        500, 300,    760,   50,        1, -254,     //BadyFront          
        180, 200,    580,  150,      247, -206,     //ArmFrontLeft_Basic 
        180, 200,    400,  150,     -225, -208,     //ArmFrontRight_Basic      
        635, 646,    815,  372,        0,  117,     //Face               
        400, 200,      0,  150,        1,  126,     //EyesFront_Open     
         24, 24,     120,  994,      -45,  122,     //EyeballLeft         
         24, 24,     120,  994,       45,  122,     //EyeballRight       
        665, 668,    150,  350,        0,  117,     //HatFront           
        150, 150,      0,  466,      262 + 5, -321 + 10,     //HandLeft_Paper     
        150, 150,      0,  616,     -247 - 20, -315 + 10,     //HandRight_Paper    
        120, 120,      0,  886,      262, -321,     //HandLeft_Rock
        120, 120,      0,  766,     -247, -315,     //HandRight_Rock      
        100, 12,       0, 1006,      -89,  233,     //EyebrowLeft        
        100, 12,       0, 1006,       89,  233      //EyebrowRight       
    };
}
