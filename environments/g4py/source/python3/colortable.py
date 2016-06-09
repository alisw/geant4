"""
# ==================================================================
#   Python module
#
#   color table
#
#                                              Q, 2005
# ==================================================================
"""
#$Id: colortable.py,v 1.1 2010/12/02 08:22:21 kmura Exp $


def int_rgb(name):
  return _colortable[name]


def float_rgb(name):
  rgb = _colortable[name]
  return (rgb[0]/255., rgb[1]/255., rgb[2]/255.)


# ==================================================================
# RGB color table (/usr/lib/X11/rgb.txt)
# ==================================================================
_colortable = { }
_colortable["snow"] = (255, 250, 250)
_colortable["ghost"] = (248, 248, 255)
_colortable["GhostWhite"] = (248, 248, 255)
_colortable["white"] = (245, 245, 245)
_colortable["WhiteSmoke"] = (245, 245, 245)
_colortable["gainsboro"] = (220, 220, 220)
_colortable["floral"] = (255, 250, 240)
_colortable["FloralWhite"] = (255, 250, 240)
_colortable["old"] = (253, 245, 230)
_colortable["OldLace"] = (253, 245, 230)
_colortable["linen"] = (250, 240, 230)
_colortable["antique"] = (250, 235, 215)
_colortable["AntiqueWhite"] = (250, 235, 215)
_colortable["papaya"] = (255, 239, 213)
_colortable["PapayaWhip"] = (255, 239, 213)
_colortable["blanched"] = (255, 235, 205)
_colortable["BlanchedAlmond"] = (255, 235, 205)
_colortable["bisque"] = (255, 228, 196)
_colortable["peach"] = (255, 218, 185)
_colortable["PeachPuff"] = (255, 218, 185)
_colortable["navajo"] = (255, 222, 173)
_colortable["NavajoWhite"] = (255, 222, 173)
_colortable["moccasin"] = (255, 228, 181)
_colortable["cornsilk"] = (255, 248, 220)
_colortable["ivory"] = (255, 255, 240)
_colortable["lemon"] = (255, 250, 205)
_colortable["LemonChiffon"] = (255, 250, 205)
_colortable["seashell"] = (255, 245, 238)
_colortable["honeydew"] = (240, 255, 240)
_colortable["mint"] = (245, 255, 250)
_colortable["MintCream"] = (245, 255, 250)
_colortable["azure"] = (240, 255, 255)
_colortable["alice"] = (240, 248, 255)
_colortable["AliceBlue"] = (240, 248, 255)
_colortable["lavender"] = (230, 230, 250)
_colortable["lavender"] = (255, 240, 245)
_colortable["LavenderBlush"] = (255, 240, 245)
_colortable["misty"] = (255, 228, 225)
_colortable["MistyRose"] = (255, 228, 225)
_colortable["white"] = (255, 255, 255)
_colortable["black"] = (0, 0, 0)
_colortable["dark"] = (47, 79, 79)
_colortable["DarkSlateGray"] = (47, 79, 79)
_colortable["dark"] = (47, 79, 79)
_colortable["DarkSlateGrey"] = (47, 79, 79)
_colortable["dim"] = (105, 105, 105)
_colortable["DimGray"] = (105, 105, 105)
_colortable["dim"] = (105, 105, 105)
_colortable["DimGrey"] = (105, 105, 105)
_colortable["slate"] = (112, 128, 144)
_colortable["SlateGray"] = (112, 128, 144)
_colortable["slate"] = (112, 128, 144)
_colortable["SlateGrey"] = (112, 128, 144)
_colortable["light"] = (119, 136, 153)
_colortable["LightSlateGray"] = (119, 136, 153)
_colortable["light"] = (119, 136, 153)
_colortable["LightSlateGrey"] = (119, 136, 153)
_colortable["gray"] = (190, 190, 190)
_colortable["grey"] = (190, 190, 190)
_colortable["light"] = (211, 211, 211)
_colortable["LightGrey"] = (211, 211, 211)
_colortable["light"] = (211, 211, 211)
_colortable["LightGray"] = (211, 211, 211)
_colortable["midnight"] = (25, 25, 112)
_colortable["MidnightBlue"] = (25, 25, 112)
_colortable["navy"] = (0, 0, 128)
_colortable["navy"] = (0, 0, 128)
_colortable["NavyBlue"] = (0, 0, 128)
_colortable["cornflower"] = (100, 149, 237)
_colortable["CornflowerBlue"] = (100, 149, 237)
_colortable["dark"] = (72, 61, 139)
_colortable["DarkSlateBlue"] = (72, 61, 139)
_colortable["slate"] = (106, 90, 205)
_colortable["SlateBlue"] = (106, 90, 205)
_colortable["medium"] = (123, 104, 238)
_colortable["MediumSlateBlue"] = (123, 104, 238)
_colortable["light"] = (132, 112, 255)
_colortable["LightSlateBlue"] = (132, 112, 255)
_colortable["medium"] = (0, 0, 205)
_colortable["MediumBlue"] = (0, 0, 205)
_colortable["royal"] = (65, 105, 225)
_colortable["RoyalBlue"] = (65, 105, 225)
_colortable["blue"] = (0, 0, 255)
_colortable["dodger"] = (30, 144, 255)
_colortable["DodgerBlue"] = (30, 144, 255)
_colortable["deep"] = (0, 191, 255)
_colortable["DeepSkyBlue"] = (0, 191, 255)
_colortable["sky"] = (135, 206, 235)
_colortable["SkyBlue"] = (135, 206, 235)
_colortable["light"] = (135, 206, 250)
_colortable["LightSkyBlue"] = (135, 206, 250)
_colortable["steel"] = (70, 130, 180)
_colortable["SteelBlue"] = (70, 130, 180)
_colortable["light"] = (176, 196, 222)
_colortable["LightSteelBlue"] = (176, 196, 222)
_colortable["light"] = (173, 216, 230)
_colortable["LightBlue"] = (173, 216, 230)
_colortable["powder"] = (176, 224, 230)
_colortable["PowderBlue"] = (176, 224, 230)
_colortable["pale"] = (175, 238, 238)
_colortable["PaleTurquoise"] = (175, 238, 238)
_colortable["dark"] = (0, 206, 209)
_colortable["DarkTurquoise"] = (0, 206, 209)
_colortable["medium"] = (72, 209, 204)
_colortable["MediumTurquoise"] = (72, 209, 204)
_colortable["turquoise"] = (64, 224, 208)
_colortable["cyan"] = (0, 255, 255)
_colortable["light"] = (224, 255, 255)
_colortable["LightCyan"] = (224, 255, 255)
_colortable["cadet"] = (95, 158, 160)
_colortable["CadetBlue"] = (95, 158, 160)
_colortable["medium"] = (102, 205, 170)
_colortable["MediumAquamarine"] = (102, 205, 170)
_colortable["aquamarine"] = (127, 255, 212)
_colortable["dark"] = (0, 100, 0)
_colortable["DarkGreen"] = (0, 100, 0)
_colortable["dark"] = (85, 107, 47)
_colortable["DarkOliveGreen"] = (85, 107, 47)
_colortable["dark"] = (143, 188, 143)
_colortable["DarkSeaGreen"] = (143, 188, 143)
_colortable["sea"] = (46, 139, 87)
_colortable["SeaGreen"] = (46, 139, 87)
_colortable["medium"] = (60, 179, 113)
_colortable["MediumSeaGreen"] = (60, 179, 113)
_colortable["light"] = (32, 178, 170)
_colortable["LightSeaGreen"] = (32, 178, 170)
_colortable["pale"] = (152, 251, 152)
_colortable["PaleGreen"] = (152, 251, 152)
_colortable["spring"] = (0, 255, 127)
_colortable["SpringGreen"] = (0, 255, 127)
_colortable["lawn"] = (124, 252, 0)
_colortable["LawnGreen"] = (124, 252, 0)
_colortable["green"] = (0, 255, 0)
_colortable["chartreuse"] = (127, 255, 0)
_colortable["medium"] = (0, 250, 154)
_colortable["MediumSpringGreen"] = (0, 250, 154)
_colortable["green"] = (173, 255, 47)
_colortable["GreenYellow"] = (173, 255, 47)
_colortable["lime"] = (50, 205, 50)
_colortable["LimeGreen"] = (50, 205, 50)
_colortable["yellow"] = (154, 205, 50)
_colortable["YellowGreen"] = (154, 205, 50)
_colortable["forest"] = (34, 139, 34)
_colortable["ForestGreen"] = (34, 139, 34)
_colortable["olive"] = (107, 142, 35)
_colortable["OliveDrab"] = (107, 142, 35)
_colortable["dark"] = (189, 183, 107)
_colortable["DarkKhaki"] = (189, 183, 107)
_colortable["khaki"] = (240, 230, 140)
_colortable["pale"] = (238, 232, 170)
_colortable["PaleGoldenrod"] = (238, 232, 170)
_colortable["light"] = (250, 250, 210)
_colortable["LightGoldenrodYellow"] = (250, 250, 210)
_colortable["light"] = (255, 255, 224)
_colortable["LightYellow"] = (255, 255, 224)
_colortable["yellow"] = (255, 255, 0)
_colortable["gold"] = (255, 215, 0)
_colortable["light"] = (238, 221, 130)
_colortable["LightGoldenrod"] = (238, 221, 130)
_colortable["goldenrod"] = (218, 165, 32)
_colortable["dark"] = (184, 134, 11)
_colortable["DarkGoldenrod"] = (184, 134, 11)
_colortable["rosy"] = (188, 143, 143)
_colortable["RosyBrown"] = (188, 143, 143)
_colortable["indian"] = (205, 92, 92)
_colortable["IndianRed"] = (205, 92, 92)
_colortable["saddle"] = (139, 69, 19)
_colortable["SaddleBrown"] = (139, 69, 19)
_colortable["sienna"] = (160, 82, 45)
_colortable["peru"] = (205, 133, 63)
_colortable["burlywood"] = (222, 184, 135)
_colortable["beige"] = (245, 245, 220)
_colortable["wheat"] = (245, 222, 179)
_colortable["sandy"] = (244, 164, 96)
_colortable["SandyBrown"] = (244, 164, 96)
_colortable["tan"] = (210, 180, 140)
_colortable["chocolate"] = (210, 105, 30)
_colortable["firebrick"] = (178, 34, 34)
_colortable["brown"] = (165, 42, 42)
_colortable["dark"] = (233, 150, 122)
_colortable["DarkSalmon"] = (233, 150, 122)
_colortable["salmon"] = (250, 128, 114)
_colortable["light"] = (255, 160, 122)
_colortable["LightSalmon"] = (255, 160, 122)
_colortable["orange"] = (255, 165, 0)
_colortable["dark"] = (255, 140, 0)
_colortable["DarkOrange"] = (255, 140, 0)
_colortable["coral"] = (255, 127, 80)
_colortable["light"] = (240, 128, 128)
_colortable["LightCoral"] = (240, 128, 128)
_colortable["tomato"] = (255, 99, 71)
_colortable["orange"] = (255, 69, 0)
_colortable["OrangeRed"] = (255, 69, 0)
_colortable["red"] = (255, 0, 0)
_colortable["hot"] = (255, 105, 180)
_colortable["HotPink"] = (255, 105, 180)
_colortable["deep"] = (255, 20, 147)
_colortable["DeepPink"] = (255, 20, 147)
_colortable["pink"] = (255, 192, 203)
_colortable["light"] = (255, 182, 193)
_colortable["LightPink"] = (255, 182, 193)
_colortable["pale"] = (219, 112, 147)
_colortable["PaleVioletRed"] = (219, 112, 147)
_colortable["maroon"] = (176, 48, 96)
_colortable["medium"] = (199, 21, 133)
_colortable["MediumVioletRed"] = (199, 21, 133)
_colortable["violet"] = (208, 32, 144)
_colortable["VioletRed"] = (208, 32, 144)
_colortable["magenta"] = (255, 0, 255)
_colortable["violet"] = (238, 130, 238)
_colortable["plum"] = (221, 160, 221)
_colortable["orchid"] = (218, 112, 214)
_colortable["medium"] = (186, 85, 211)
_colortable["MediumOrchid"] = (186, 85, 211)
_colortable["dark"] = (153, 50, 204)
_colortable["DarkOrchid"] = (153, 50, 204)
_colortable["dark"] = (148, 0, 211)
_colortable["DarkViolet"] = (148, 0, 211)
_colortable["blue"] = (138, 43, 226)
_colortable["BlueViolet"] = (138, 43, 226)
_colortable["purple"] = (160, 32, 240)
_colortable["medium"] = (147, 112, 219)
_colortable["MediumPurple"] = (147, 112, 219)
_colortable["thistle"] = (216, 191, 216)
_colortable["snow1"] = (255, 250, 250)
_colortable["snow2"] = (238, 233, 233)
_colortable["snow3"] = (205, 201, 201)
_colortable["snow4"] = (139, 137, 137)
_colortable["seashell1"] = (255, 245, 238)
_colortable["seashell2"] = (238, 229, 222)
_colortable["seashell3"] = (205, 197, 191)
_colortable["seashell4"] = (139, 134, 130)
_colortable["AntiqueWhite1"] = (255, 239, 219)
_colortable["AntiqueWhite2"] = (238, 223, 204)
_colortable["AntiqueWhite3"] = (205, 192, 176)
_colortable["AntiqueWhite4"] = (139, 131, 120)
_colortable["bisque1"] = (255, 228, 196)
_colortable["bisque2"] = (238, 213, 183)
_colortable["bisque3"] = (205, 183, 158)
_colortable["bisque4"] = (139, 125, 107)
_colortable["PeachPuff1"] = (255, 218, 185)
_colortable["PeachPuff2"] = (238, 203, 173)
_colortable["PeachPuff3"] = (205, 175, 149)
_colortable["PeachPuff4"] = (139, 119, 101)
_colortable["NavajoWhite1"] = (255, 222, 173)
_colortable["NavajoWhite2"] = (238, 207, 161)
_colortable["NavajoWhite3"] = (205, 179, 139)
_colortable["NavajoWhite4"] = (139, 121, 94)
_colortable["LemonChiffon1"] = (255, 250, 205)
_colortable["LemonChiffon2"] = (238, 233, 191)
_colortable["LemonChiffon3"] = (205, 201, 165)
_colortable["LemonChiffon4"] = (139, 137, 112)
_colortable["cornsilk1"] = (255, 248, 220)
_colortable["cornsilk2"] = (238, 232, 205)
_colortable["cornsilk3"] = (205, 200, 177)
_colortable["cornsilk4"] = (139, 136, 120)
_colortable["ivory1"] = (255, 255, 240)
_colortable["ivory2"] = (238, 238, 224)
_colortable["ivory3"] = (205, 205, 193)
_colortable["ivory4"] = (139, 139, 131)
_colortable["honeydew1"] = (240, 255, 240)
_colortable["honeydew2"] = (224, 238, 224)
_colortable["honeydew3"] = (193, 205, 193)
_colortable["honeydew4"] = (131, 139, 131)
_colortable["LavenderBlush1"] = (255, 240, 245)
_colortable["LavenderBlush2"] = (238, 224, 229)
_colortable["LavenderBlush3"] = (205, 193, 197)
_colortable["LavenderBlush4"] = (139, 131, 134)
_colortable["MistyRose1"] = (255, 228, 225)
_colortable["MistyRose2"] = (238, 213, 210)
_colortable["MistyRose3"] = (205, 183, 181)
_colortable["MistyRose4"] = (139, 125, 123)
_colortable["azure1"] = (240, 255, 255)
_colortable["azure2"] = (224, 238, 238)
_colortable["azure3"] = (193, 205, 205)
_colortable["azure4"] = (131, 139, 139)
_colortable["SlateBlue1"] = (131, 111, 255)
_colortable["SlateBlue2"] = (122, 103, 238)
_colortable["SlateBlue3"] = (105, 89, 205)
_colortable["SlateBlue4"] = (71, 60, 139)
_colortable["RoyalBlue1"] = (72, 118, 255)
_colortable["RoyalBlue2"] = (67, 110, 238)
_colortable["RoyalBlue3"] = (58, 95, 205)
_colortable["RoyalBlue4"] = (39, 64, 139)
_colortable["blue1"] = (0, 0, 255)
_colortable["blue2"] = (0, 0, 238)
_colortable["blue3"] = (0, 0, 205)
_colortable["blue4"] = (0, 0, 139)
_colortable["DodgerBlue1"] = (30, 144, 255)
_colortable["DodgerBlue2"] = (28, 134, 238)
_colortable["DodgerBlue3"] = (24, 116, 205)
_colortable["DodgerBlue4"] = (16, 78, 139)
_colortable["SteelBlue1"] = (99, 184, 255)
_colortable["SteelBlue2"] = (92, 172, 238)
_colortable["SteelBlue3"] = (79, 148, 205)
_colortable["SteelBlue4"] = (54, 100, 139)
_colortable["DeepSkyBlue1"] = (0, 191, 255)
_colortable["DeepSkyBlue2"] = (0, 178, 238)
_colortable["DeepSkyBlue3"] = (0, 154, 205)
_colortable["DeepSkyBlue4"] = (0, 104, 139)
_colortable["SkyBlue1"] = (135, 206, 255)
_colortable["SkyBlue2"] = (126, 192, 238)
_colortable["SkyBlue3"] = (108, 166, 205)
_colortable["SkyBlue4"] = (74, 112, 139)
_colortable["LightSkyBlue1"] = (176, 226, 255)
_colortable["LightSkyBlue2"] = (164, 211, 238)
_colortable["LightSkyBlue3"] = (141, 182, 205)
_colortable["LightSkyBlue4"] = (96, 123, 139)
_colortable["SlateGray1"] = (198, 226, 255)
_colortable["SlateGray2"] = (185, 211, 238)
_colortable["SlateGray3"] = (159, 182, 205)
_colortable["SlateGray4"] = (108, 123, 139)
_colortable["LightSteelBlue1"] = (202, 225, 255)
_colortable["LightSteelBlue2"] = (188, 210, 238)
_colortable["LightSteelBlue3"] = (162, 181, 205)
_colortable["LightSteelBlue4"] = (110, 123, 139)
_colortable["LightBlue1"] = (191, 239, 255)
_colortable["LightBlue2"] = (178, 223, 238)
_colortable["LightBlue3"] = (154, 192, 205)
_colortable["LightBlue4"] = (104, 131, 139)
_colortable["LightCyan1"] = (224, 255, 255)
_colortable["LightCyan2"] = (209, 238, 238)
_colortable["LightCyan3"] = (180, 205, 205)
_colortable["LightCyan4"] = (122, 139, 139)
_colortable["PaleTurquoise1"] = (187, 255, 255)
_colortable["PaleTurquoise2"] = (174, 238, 238)
_colortable["PaleTurquoise3"] = (150, 205, 205)
_colortable["PaleTurquoise4"] = (102, 139, 139)
_colortable["CadetBlue1"] = (152, 245, 255)
_colortable["CadetBlue2"] = (142, 229, 238)
_colortable["CadetBlue3"] = (122, 197, 205)
_colortable["CadetBlue4"] = (83, 134, 139)
_colortable["turquoise1"] = (0, 245, 255)
_colortable["turquoise2"] = (0, 229, 238)
_colortable["turquoise3"] = (0, 197, 205)
_colortable["turquoise4"] = (0, 134, 139)
_colortable["cyan1"] = (0, 255, 255)
_colortable["cyan2"] = (0, 238, 238)
_colortable["cyan3"] = (0, 205, 205)
_colortable["cyan4"] = (0, 139, 139)
_colortable["DarkSlateGray1"] = (151, 255, 255)
_colortable["DarkSlateGray2"] = (141, 238, 238)
_colortable["DarkSlateGray3"] = (121, 205, 205)
_colortable["DarkSlateGray4"] = (82, 139, 139)
_colortable["aquamarine1"] = (127, 255, 212)
_colortable["aquamarine2"] = (118, 238, 198)
_colortable["aquamarine3"] = (102, 205, 170)
_colortable["aquamarine4"] = (69, 139, 116)
_colortable["DarkSeaGreen1"] = (193, 255, 193)
_colortable["DarkSeaGreen2"] = (180, 238, 180)
_colortable["DarkSeaGreen3"] = (155, 205, 155)
_colortable["DarkSeaGreen4"] = (105, 139, 105)
_colortable["SeaGreen1"] = (84, 255, 159)
_colortable["SeaGreen2"] = (78, 238, 148)
_colortable["SeaGreen3"] = (67, 205, 128)
_colortable["SeaGreen4"] = (46, 139, 87)
_colortable["PaleGreen1"] = (154, 255, 154)
_colortable["PaleGreen2"] = (144, 238, 144)
_colortable["PaleGreen3"] = (124, 205, 124)
_colortable["PaleGreen4"] = (84, 139, 84)
_colortable["SpringGreen1"] = (0, 255, 127)
_colortable["SpringGreen2"] = (0, 238, 118)
_colortable["SpringGreen3"] = (0, 205, 102)
_colortable["SpringGreen4"] = (0, 139, 69)
_colortable["green1"] = (0, 255, 0)
_colortable["green2"] = (0, 238, 0)
_colortable["green3"] = (0, 205, 0)
_colortable["green4"] = (0, 139, 0)
_colortable["chartreuse1"] = (127, 255, 0)
_colortable["chartreuse2"] = (118, 238, 0)
_colortable["chartreuse3"] = (102, 205, 0)
_colortable["chartreuse4"] = (69, 139, 0)
_colortable["OliveDrab1"] = (192, 255, 62)
_colortable["OliveDrab2"] = (179, 238, 58)
_colortable["OliveDrab3"] = (154, 205, 50)
_colortable["OliveDrab4"] = (105, 139, 34)
_colortable["DarkOliveGreen1"] = (202, 255, 112)
_colortable["DarkOliveGreen2"] = (188, 238, 104)
_colortable["DarkOliveGreen3"] = (162, 205, 90)
_colortable["DarkOliveGreen4"] = (110, 139, 61)
_colortable["khaki1"] = (255, 246, 143)
_colortable["khaki2"] = (238, 230, 133)
_colortable["khaki3"] = (205, 198, 115)
_colortable["khaki4"] = (139, 134, 78)
_colortable["LightGoldenrod1"] = (255, 236, 139)
_colortable["LightGoldenrod2"] = (238, 220, 130)
_colortable["LightGoldenrod3"] = (205, 190, 112)
_colortable["LightGoldenrod4"] = (139, 129, 76)
_colortable["LightYellow1"] = (255, 255, 224)
_colortable["LightYellow2"] = (238, 238, 209)
_colortable["LightYellow3"] = (205, 205, 180)
_colortable["LightYellow4"] = (139, 139, 122)
_colortable["yellow1"] = (255, 255, 0)
_colortable["yellow2"] = (238, 238, 0)
_colortable["yellow3"] = (205, 205, 0)
_colortable["yellow4"] = (139, 139, 0)
_colortable["gold1"] = (255, 215, 0)
_colortable["gold2"] = (238, 201, 0)
_colortable["gold3"] = (205, 173, 0)
_colortable["gold4"] = (139, 117, 0)
_colortable["goldenrod1"] = (255, 193, 37)
_colortable["goldenrod2"] = (238, 180, 34)
_colortable["goldenrod3"] = (205, 155, 29)
_colortable["goldenrod4"] = (139, 105, 20)
_colortable["DarkGoldenrod1"] = (255, 185, 15)
_colortable["DarkGoldenrod2"] = (238, 173, 14)
_colortable["DarkGoldenrod3"] = (205, 149, 12)
_colortable["DarkGoldenrod4"] = (139, 101, 8)
_colortable["RosyBrown1"] = (255, 193, 193)
_colortable["RosyBrown2"] = (238, 180, 180)
_colortable["RosyBrown3"] = (205, 155, 155)
_colortable["RosyBrown4"] = (139, 105, 105)
_colortable["IndianRed1"] = (255, 106, 106)
_colortable["IndianRed2"] = (238, 99, 99)
_colortable["IndianRed3"] = (205, 85, 85)
_colortable["IndianRed4"] = (139, 58, 58)
_colortable["sienna1"] = (255, 130, 71)
_colortable["sienna2"] = (238, 121, 66)
_colortable["sienna3"] = (205, 104, 57)
_colortable["sienna4"] = (139, 71, 38)
_colortable["burlywood1"] = (255, 211, 155)
_colortable["burlywood2"] = (238, 197, 145)
_colortable["burlywood3"] = (205, 170, 125)
_colortable["burlywood4"] = (139, 115, 85)
_colortable["wheat1"] = (255, 231, 186)
_colortable["wheat2"] = (238, 216, 174)
_colortable["wheat3"] = (205, 186, 150)
_colortable["wheat4"] = (139, 126, 102)
_colortable["tan1"] = (255, 165, 79)
_colortable["tan2"] = (238, 154, 73)
_colortable["tan3"] = (205, 133, 63)
_colortable["tan4"] = (139, 90, 43)
_colortable["chocolate1"] = (255, 127, 36)
_colortable["chocolate2"] = (238, 118, 33)
_colortable["chocolate3"] = (205, 102, 29)
_colortable["chocolate4"] = (139, 69, 19)
_colortable["firebrick1"] = (255, 48, 48)
_colortable["firebrick2"] = (238, 44, 44)
_colortable["firebrick3"] = (205, 38, 38)
_colortable["firebrick4"] = (139, 26, 26)
_colortable["brown1"] = (255, 64, 64)
_colortable["brown2"] = (238, 59, 59)
_colortable["brown3"] = (205, 51, 51)
_colortable["brown4"] = (139, 35, 35)
_colortable["salmon1"] = (255, 140, 105)
_colortable["salmon2"] = (238, 130, 98)
_colortable["salmon3"] = (205, 112, 84)
_colortable["salmon4"] = (139, 76, 57)
_colortable["LightSalmon1"] = (255, 160, 122)
_colortable["LightSalmon2"] = (238, 149, 114)
_colortable["LightSalmon3"] = (205, 129, 98)
_colortable["LightSalmon4"] = (139, 87, 66)
_colortable["orange1"] = (255, 165, 0)
_colortable["orange2"] = (238, 154, 0)
_colortable["orange3"] = (205, 133, 0)
_colortable["orange4"] = (139, 90, 0)
_colortable["DarkOrange1"] = (255, 127, 0)
_colortable["DarkOrange2"] = (238, 118, 0)
_colortable["DarkOrange3"] = (205, 102, 0)
_colortable["DarkOrange4"] = (139, 69, 0)
_colortable["coral1"] = (255, 114, 86)
_colortable["coral2"] = (238, 106, 80)
_colortable["coral3"] = (205, 91, 69)
_colortable["coral4"] = (139, 62, 47)
_colortable["tomato1"] = (255, 99, 71)
_colortable["tomato2"] = (238, 92, 66)
_colortable["tomato3"] = (205, 79, 57)
_colortable["tomato4"] = (139, 54, 38)
_colortable["OrangeRed1"] = (255, 69, 0)
_colortable["OrangeRed2"] = (238, 64, 0)
_colortable["OrangeRed3"] = (205, 55, 0)
_colortable["OrangeRed4"] = (139, 37, 0)
_colortable["red1"] = (255, 0, 0)
_colortable["red2"] = (238, 0, 0)
_colortable["red3"] = (205, 0, 0)
_colortable["red4"] = (139, 0, 0)
_colortable["DeepPink1"] = (255, 20, 147)
_colortable["DeepPink2"] = (238, 18, 137)
_colortable["DeepPink3"] = (205, 16, 118)
_colortable["DeepPink4"] = (139, 10, 80)
_colortable["HotPink1"] = (255, 110, 180)
_colortable["HotPink2"] = (238, 106, 167)
_colortable["HotPink3"] = (205, 96, 144)
_colortable["HotPink4"] = (139, 58, 98)
_colortable["pink1"] = (255, 181, 197)
_colortable["pink2"] = (238, 169, 184)
_colortable["pink3"] = (205, 145, 158)
_colortable["pink4"] = (139, 99, 108)
_colortable["LightPink1"] = (255, 174, 185)
_colortable["LightPink2"] = (238, 162, 173)
_colortable["LightPink3"] = (205, 140, 149)
_colortable["LightPink4"] = (139, 95, 101)
_colortable["PaleVioletRed1"] = (255, 130, 171)
_colortable["PaleVioletRed2"] = (238, 121, 159)
_colortable["PaleVioletRed3"] = (205, 104, 137)
_colortable["PaleVioletRed4"] = (139, 71, 93)
_colortable["maroon1"] = (255, 52, 179)
_colortable["maroon2"] = (238, 48, 167)
_colortable["maroon3"] = (205, 41, 144)
_colortable["maroon4"] = (139, 28, 98)
_colortable["VioletRed1"] = (255, 62, 150)
_colortable["VioletRed2"] = (238, 58, 140)
_colortable["VioletRed3"] = (205, 50, 120)
_colortable["VioletRed4"] = (139, 34, 82)
_colortable["magenta1"] = (255, 0, 255)
_colortable["magenta2"] = (238, 0, 238)
_colortable["magenta3"] = (205, 0, 205)
_colortable["magenta4"] = (139, 0, 139)
_colortable["orchid1"] = (255, 131, 250)
_colortable["orchid2"] = (238, 122, 233)
_colortable["orchid3"] = (205, 105, 201)
_colortable["orchid4"] = (139, 71, 137)
_colortable["plum1"] = (255, 187, 255)
_colortable["plum2"] = (238, 174, 238)
_colortable["plum3"] = (205, 150, 205)
_colortable["plum4"] = (139, 102, 139)
_colortable["MediumOrchid1"] = (224, 102, 255)
_colortable["MediumOrchid2"] = (209, 95, 238)
_colortable["MediumOrchid3"] = (180, 82, 205)
_colortable["MediumOrchid4"] = (122, 55, 139)
_colortable["DarkOrchid1"] = (191, 62, 255)
_colortable["DarkOrchid2"] = (178, 58, 238)
_colortable["DarkOrchid3"] = (154, 50, 205)
_colortable["DarkOrchid4"] = (104, 34, 139)
_colortable["purple1"] = (155, 48, 255)
_colortable["purple2"] = (145, 44, 238)
_colortable["purple3"] = (125, 38, 205)
_colortable["purple4"] = (85, 26, 139)
_colortable["MediumPurple1"] = (171, 130, 255)
_colortable["MediumPurple2"] = (159, 121, 238)
_colortable["MediumPurple3"] = (137, 104, 205)
_colortable["MediumPurple4"] = (93, 71, 139)
_colortable["thistle1"] = (255, 225, 255)
_colortable["thistle2"] = (238, 210, 238)
_colortable["thistle3"] = (205, 181, 205)
_colortable["thistle4"] = (139, 123, 139)
_colortable["gray0"] = (0, 0, 0)
_colortable["grey0"] = (0, 0, 0)
_colortable["gray1"] = (3, 3, 3)
_colortable["grey1"] = (3, 3, 3)
_colortable["gray2"] = (5, 5, 5)
_colortable["grey2"] = (5, 5, 5)
_colortable["gray3"] = (8, 8, 8)
_colortable["grey3"] = (8, 8, 8)
_colortable["gray4"] = (10, 10, 10)
_colortable["grey4"] = (10, 10, 10)
_colortable["gray5"] = (13, 13, 13)
_colortable["grey5"] = (13, 13, 13)
_colortable["gray6"] = (15, 15, 15)
_colortable["grey6"] = (15, 15, 15)
_colortable["gray7"] = (18, 18, 18)
_colortable["grey7"] = (18, 18, 18)
_colortable["gray8"] = (20, 20, 20)
_colortable["grey8"] = (20, 20, 20)
_colortable["gray9"] = (23, 23, 23)
_colortable["grey9"] = (23, 23, 23)
_colortable["gray10"] = (26, 26, 26)
_colortable["grey10"] = (26, 26, 26)
_colortable["gray11"] = (28, 28, 28)
_colortable["grey11"] = (28, 28, 28)
_colortable["gray12"] = (31, 31, 31)
_colortable["grey12"] = (31, 31, 31)
_colortable["gray13"] = (33, 33, 33)
_colortable["grey13"] = (33, 33, 33)
_colortable["gray14"] = (36, 36, 36)
_colortable["grey14"] = (36, 36, 36)
_colortable["gray15"] = (38, 38, 38)
_colortable["grey15"] = (38, 38, 38)
_colortable["gray16"] = (41, 41, 41)
_colortable["grey16"] = (41, 41, 41)
_colortable["gray17"] = (43, 43, 43)
_colortable["grey17"] = (43, 43, 43)
_colortable["gray18"] = (46, 46, 46)
_colortable["grey18"] = (46, 46, 46)
_colortable["gray19"] = (48, 48, 48)
_colortable["grey19"] = (48, 48, 48)
_colortable["gray20"] = (51, 51, 51)
_colortable["grey20"] = (51, 51, 51)
_colortable["gray21"] = (54, 54, 54)
_colortable["grey21"] = (54, 54, 54)
_colortable["gray22"] = (56, 56, 56)
_colortable["grey22"] = (56, 56, 56)
_colortable["gray23"] = (59, 59, 59)
_colortable["grey23"] = (59, 59, 59)
_colortable["gray24"] = (61, 61, 61)
_colortable["grey24"] = (61, 61, 61)
_colortable["gray25"] = (64, 64, 64)
_colortable["grey25"] = (64, 64, 64)
_colortable["gray26"] = (66, 66, 66)
_colortable["grey26"] = (66, 66, 66)
_colortable["gray27"] = (69, 69, 69)
_colortable["grey27"] = (69, 69, 69)
_colortable["gray28"] = (71, 71, 71)
_colortable["grey28"] = (71, 71, 71)
_colortable["gray29"] = (74, 74, 74)
_colortable["grey29"] = (74, 74, 74)
_colortable["gray30"] = (77, 77, 77)
_colortable["grey30"] = (77, 77, 77)
_colortable["gray31"] = (79, 79, 79)
_colortable["grey31"] = (79, 79, 79)
_colortable["gray32"] = (82, 82, 82)
_colortable["grey32"] = (82, 82, 82)
_colortable["gray33"] = (84, 84, 84)
_colortable["grey33"] = (84, 84, 84)
_colortable["gray34"] = (87, 87, 87)
_colortable["grey34"] = (87, 87, 87)
_colortable["gray35"] = (89, 89, 89)
_colortable["grey35"] = (89, 89, 89)
_colortable["gray36"] = (92, 92, 92)
_colortable["grey36"] = (92, 92, 92)
_colortable["gray37"] = (94, 94, 94)
_colortable["grey37"] = (94, 94, 94)
_colortable["gray38"] = (97, 97, 97)
_colortable["grey38"] = (97, 97, 97)
_colortable["gray39"] = (99, 99, 99)
_colortable["grey39"] = (99, 99, 99)
_colortable["gray40"] = (102, 102, 102)
_colortable["grey40"] = (102, 102, 102)
_colortable["gray41"] = (105, 105, 105)
_colortable["grey41"] = (105, 105, 105)
_colortable["gray42"] = (107, 107, 107)
_colortable["grey42"] = (107, 107, 107)
_colortable["gray43"] = (110, 110, 110)
_colortable["grey43"] = (110, 110, 110)
_colortable["gray44"] = (112, 112, 112)
_colortable["grey44"] = (112, 112, 112)
_colortable["gray45"] = (115, 115, 115)
_colortable["grey45"] = (115, 115, 115)
_colortable["gray46"] = (117, 117, 117)
_colortable["grey46"] = (117, 117, 117)
_colortable["gray47"] = (120, 120, 120)
_colortable["grey47"] = (120, 120, 120)
_colortable["gray48"] = (122, 122, 122)
_colortable["grey48"] = (122, 122, 122)
_colortable["gray49"] = (125, 125, 125)
_colortable["grey49"] = (125, 125, 125)
_colortable["gray50"] = (127, 127, 127)
_colortable["grey50"] = (127, 127, 127)
_colortable["gray51"] = (130, 130, 130)
_colortable["grey51"] = (130, 130, 130)
_colortable["gray52"] = (133, 133, 133)
_colortable["grey52"] = (133, 133, 133)
_colortable["gray53"] = (135, 135, 135)
_colortable["grey53"] = (135, 135, 135)
_colortable["gray54"] = (138, 138, 138)
_colortable["grey54"] = (138, 138, 138)
_colortable["gray55"] = (140, 140, 140)
_colortable["grey55"] = (140, 140, 140)
_colortable["gray56"] = (143, 143, 143)
_colortable["grey56"] = (143, 143, 143)
_colortable["gray57"] = (145, 145, 145)
_colortable["grey57"] = (145, 145, 145)
_colortable["gray58"] = (148, 148, 148)
_colortable["grey58"] = (148, 148, 148)
_colortable["gray59"] = (150, 150, 150)
_colortable["grey59"] = (150, 150, 150)
_colortable["gray60"] = (153, 153, 153)
_colortable["grey60"] = (153, 153, 153)
_colortable["gray61"] = (156, 156, 156)
_colortable["grey61"] = (156, 156, 156)
_colortable["gray62"] = (158, 158, 158)
_colortable["grey62"] = (158, 158, 158)
_colortable["gray63"] = (161, 161, 161)
_colortable["grey63"] = (161, 161, 161)
_colortable["gray64"] = (163, 163, 163)
_colortable["grey64"] = (163, 163, 163)
_colortable["gray65"] = (166, 166, 166)
_colortable["grey65"] = (166, 166, 166)
_colortable["gray66"] = (168, 168, 168)
_colortable["grey66"] = (168, 168, 168)
_colortable["gray67"] = (171, 171, 171)
_colortable["grey67"] = (171, 171, 171)
_colortable["gray68"] = (173, 173, 173)
_colortable["grey68"] = (173, 173, 173)
_colortable["gray69"] = (176, 176, 176)
_colortable["grey69"] = (176, 176, 176)
_colortable["gray70"] = (179, 179, 179)
_colortable["grey70"] = (179, 179, 179)
_colortable["gray71"] = (181, 181, 181)
_colortable["grey71"] = (181, 181, 181)
_colortable["gray72"] = (184, 184, 184)
_colortable["grey72"] = (184, 184, 184)
_colortable["gray73"] = (186, 186, 186)
_colortable["grey73"] = (186, 186, 186)
_colortable["gray74"] = (189, 189, 189)
_colortable["grey74"] = (189, 189, 189)
_colortable["gray75"] = (191, 191, 191)
_colortable["grey75"] = (191, 191, 191)
_colortable["gray76"] = (194, 194, 194)
_colortable["grey76"] = (194, 194, 194)
_colortable["gray77"] = (196, 196, 196)
_colortable["grey77"] = (196, 196, 196)
_colortable["gray78"] = (199, 199, 199)
_colortable["grey78"] = (199, 199, 199)
_colortable["gray79"] = (201, 201, 201)
_colortable["grey79"] = (201, 201, 201)
_colortable["gray80"] = (204, 204, 204)
_colortable["grey80"] = (204, 204, 204)
_colortable["gray81"] = (207, 207, 207)
_colortable["grey81"] = (207, 207, 207)
_colortable["gray82"] = (209, 209, 209)
_colortable["grey82"] = (209, 209, 209)
_colortable["gray83"] = (212, 212, 212)
_colortable["grey83"] = (212, 212, 212)
_colortable["gray84"] = (214, 214, 214)
_colortable["grey84"] = (214, 214, 214)
_colortable["gray85"] = (217, 217, 217)
_colortable["grey85"] = (217, 217, 217)
_colortable["gray86"] = (219, 219, 219)
_colortable["grey86"] = (219, 219, 219)
_colortable["gray87"] = (222, 222, 222)
_colortable["grey87"] = (222, 222, 222)
_colortable["gray88"] = (224, 224, 224)
_colortable["grey88"] = (224, 224, 224)
_colortable["gray89"] = (227, 227, 227)
_colortable["grey89"] = (227, 227, 227)
_colortable["gray90"] = (229, 229, 229)
_colortable["grey90"] = (229, 229, 229)
_colortable["gray91"] = (232, 232, 232)
_colortable["grey91"] = (232, 232, 232)
_colortable["gray92"] = (235, 235, 235)
_colortable["grey92"] = (235, 235, 235)
_colortable["gray93"] = (237, 237, 237)
_colortable["grey93"] = (237, 237, 237)
_colortable["gray94"] = (240, 240, 240)
_colortable["grey94"] = (240, 240, 240)
_colortable["gray95"] = (242, 242, 242)
_colortable["grey95"] = (242, 242, 242)
_colortable["gray96"] = (245, 245, 245)
_colortable["grey96"] = (245, 245, 245)
_colortable["gray97"] = (247, 247, 247)
_colortable["grey97"] = (247, 247, 247)
_colortable["gray98"] = (250, 250, 250)
_colortable["grey98"] = (250, 250, 250)
_colortable["gray99"] = (252, 252, 252)
_colortable["grey99"] = (252, 252, 252)
_colortable["gray100"] = (255, 255, 255)
_colortable["grey100"] = (255, 255, 255)
_colortable["dark"] = (169, 169, 169)
_colortable["DarkGrey"] = (169, 169, 169)
_colortable["dark"] = (169, 169, 169)
_colortable["DarkGray"] = (169, 169, 169)
_colortable["dark"] = (0, 0, 139)
_colortable["DarkBlue"] = (0, 0, 139)
_colortable["dark"] = (0, 139, 139)
_colortable["DarkCyan"] = (0, 139, 139)
_colortable["dark"] = (139, 0, 139)
_colortable["DarkMagenta"] = (139, 0, 139)
_colortable["dark"] = (139, 0, 0)
_colortable["DarkRed"] = (139, 0, 0)
_colortable["light"] = (144, 238, 144)
_colortable["LightGreen"] = (144, 238, 144)

