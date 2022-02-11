#pragma once

namespace kenny
{
    enum class Part
    {
        EyebrowRight        = 0,
        EyebrowLeft         = 1,		    
        HandRight_Rock 	    = 2,
        HandLeft_Rock	    = 3,
        HandRight_Paper 	= 4,
        HandLeft_Paper	    = 5,
        HatFront		    = 6,
        EyeballRight        = 7,        
        EyeballLeft	        = 8,
        EyesFront_Open		= 9,
        Face			    = 10,
        ArmFrontRight_Basic = 11,
        ArmFrontLeft_Basic	= 12,
        BadyFront		    = 13,
        ArmRight_Bend	    = 14,
        ArmLeft_Bend	    = 15,
        ArmRight_Open	    = 16,
        ArmLeft_Open	    = 17,
        PantFront           = 18,
        
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

    struct KennyTexData
    {
        Vec2 size;
        Vec2 sheetPos;
        Vec2 basicPos;
    };
    
    const KennyTexData g_TexData[] = {
        100,   12,	  0, 1006,   89,  233,    //EyebrowRight            
        100,   12,	  0, 1006,  -89,  233,    //EyebrowLeft         
        120,  120,	  0,  886,  262, -321,    //HandRight_Rock 	    
        120,  120,    0,  766, -247, -315,    //HandLeft_Rock	    
        150,  150,    0,  616, -182, -296,    //HandRight_Paper 	
        150,  150,    0,  466,  197, -284,    //HandLeft_Paper	    
        665,  668,	150,  350,    0,  117,    //HatFront		    
        24,   24,	120,  994,   45,  122,    //EyeballRight                
        24,   24,	120,  994,  -45,  122,    //EyeballLeft	        
        400,  200,    0,  150,    1,  126,    //EyesFront_Open		
        635,  646,	815,  372,    0,  117,    //Face			    
        180,  200,	400,  150, -225, -208,    //ArmFrontRight_Basic 
        180,  200,	580,  150,  247, -206,    //ArmFrontLeft_Basic	
        500,  300,  760,   50,    1, -254,    //BadyFront		    
        200,  300, 1450,  718, -207, -233,    //ArmRight_Bend	    
        200,  300, 1450,  418,  221, -231,    //ArmLeft_Bend	    
        250,  150,    0,    0, -251, -201,    //ArmRight_Open	    
        250,  150,  250,    0,  263, -197,    //ArmLeft_Open	    
        450,  250, 1260,  122,    0, -325     //PantFront           
    };
}
