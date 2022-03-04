#pragma once
#include "src/VertexMat.h"

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

    struct DirX
    {
        int right;
        int left;
    };
    
    struct Style
    {
        bool eyebrow;
        DirX arm;
        DirX hand;
    };

    struct KennyTexData
    {
        spat::Vec2 size;
        spat::Vec2 sheetPos;
        spat::Vec2 basicPos;
    };
    
    const KennyTexData g_TexData[] = {
        450.0f, 250.0f,   1260.0f,  122.0f,        0.0f, -325.0f,     //PantFront             
        250.0f, 150.0f,    250.0f,    0.0f,      262.0f, -197.0f,     //ArmLeft_Open       
        250.0f, 150.0f,      0.0f,    0.0f,     -252.0f, -201.0f,     //ArmRight_Open      
        200.0f, 300.0f,   1450.0f,  418.0f,      220.0f, -231.0f,     //ArmLeft_Bend       
        200.0f, 300.0f,   1450.0f,  718.0f,     -208.0f, -233.0f,     //ArmRight_Bend      
        500.0f, 300.0f,    760.0f,   50.0f,        0.0f, -254.0f,     //BadyFront          
        180.0f, 200.0f,    580.0f,  150.0f,      246.0f, -206.0f,     //ArmFrontLeft_Basic 
        180.0f, 200.0f,    400.0f,  150.0f,     -226.0f, -208.0f,     //ArmFrontRight_Basic      
        635.0f, 646.0f,    815.0f,  372.0f,        0.0f,  117.0f,     //Face               
        400.0f, 200.0f,      0.0f,  150.0f,        0.0f,  126.0f,     //EyesFront_Open     
         24.0f,  24.0f,    120.0f,  994.0f,       45.0f,  122.0f,     //EyeballLeft         
         24.0f,  24.0f,    120.0f,  994.0f,      -45.0f,  122.0f,     //EyeballRight       
        665.0f, 668.0f,    150.0f,  350.0f,        0.0f,  117.0f,     //HatFront           
        150.0f, 150.0f,      0.0f,  466.0f,      262.0f, -321.0f,     //HandLeft_Paper     
        150.0f, 150.0f,      0.0f,  616.0f,     -247.0f, -315.0f,     //HandRight_Paper    
        120.0f, 120.0f,      0.0f,  886.0f,      262.0f, -321.0f,     //HandLeft_Rock
        120.0f, 120.0f,      0.0f,  766.0f,     -247.0f, -315.0f,     //HandRight_Rock      
        100.0f,  12.0f,      0.0f, 1006.0f,      -89.0f,  233.0f,     //EyebrowLeft        
        100.0f,  12.0f,      0.0f, 1006.0f,       89.0f,  233.0f      //EyebrowRight       
    };
}
