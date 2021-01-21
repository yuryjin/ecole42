StartingPage();

function StartingPage() {
  var red = document.getElementById("red").value,
    green = document.getElementById("green").value,
    blue = document.getElementById("blue").value;
  alpha = document.getElementById("alpha").value;
  hue = document.getElementById("hue").value;
  saturation = document.getElementById("saturation").value;
  lightness = document.getElementById("lightness").value;

  document.getElementById("redvalue").innerHTML = red;
  document.getElementById("greenvalue").innerHTML = green;
  document.getElementById("bluevalue").innerHTML = blue;
  document.getElementById("alphavalue").innerHTML = alpha * 100 + "%";
  document.getElementById("huevalue").innerHTML = hue;
  document.getElementById("saturationvalue").innerHTML = saturation + "%";
  document.getElementById("lightnessvalue").innerHTML = lightness + "%";

  hexred = (+red).toString(16);
  hexgreen = (+green).toString(16);
  hexblue = (+blue).toString(16);

  codered = hexred;
  codegreen = hexgreen;
  codeblue = hexblue;

  if (codered.length == 1) {
    codered = codered[0] + codered[0];
  }
  if (codegreen.length == 1) {
    codegreen = codegreen[0] + codegreen[0];
  }
  if (codeblue.length == 1) {
    codeblue = codeblue[0] + codeblue[0];
  }

  colorname = "#" + codered + codegreen + codeblue;

  if (hexred.length == 1) {
    hexred = hexred[0] + hexred[0];
  }
  if (hexgreen.length == 1) {
    hexgreen = hexgreen[0] + hexgreen[0];
  }
  if (hexblue.length == 1) {
    hexblue = hexblue[0] + hexblue[0];
  }
  if (
    hexred[0] == hexred[1] &&
    hexgreen[0] == hexgreen[1] &&
    hexblue[0] == hexblue[1]
  ) {
    hexred = hexred[0];
    hexgreen = hexgreen[0];
    hexblue = hexblue[0];
  }

  hexall = "#" + hexred + hexgreen + hexblue;
  if (codetoname(colorname)) {
    colorname = codetoname(colorname);
  } else {
    colorname = hexall;
  }

  document.getElementById("namevalue").innerHTML = "Name: " + colorname;
  document.getElementById("codevalue").innerHTML = "Code: " + hexall;
  document.getElementById("rgbvalue").innerHTML =
    "rgba(" + red + ", " + green + ", " + blue + ", " + alpha + ")";
  document.getElementById("hslvalue").innerHTML =
    "hsl(" + hue + ", " + saturation + ", " + lightness + ")";

  var display = document.getElementById("display");
  display.style.background =
    "rgba(" + red + ", " + green + ", " + blue + ", " + alpha + ")";
}

function rgbToHsl(red, green, blue) {
  (red /= 255), (green /= 255), (blue /= 255);
  var max = Math.max(red, green, blue),
    min = Math.min(red, green, blue);
  hue, saturation, (lightness = (max + min) / 2);

  if (max == min) {
    hue = saturation = 0; // achromatic
  } else {
    var d = max - min;
    saturation = lightness > 0.5 ? d / (2 - max - min) : d / (max + min);
    switch (max) {
      case red:
        hue = (green - blue) / d + (green < blue ? 6 : 0);
        break;
      case green:
        hue = (blue - red) / d + 2;
        break;
      case blue:
        hue = (red - green) / d + 4;
        break;
    }
  }
  hue = Math.round(hue * 60);
  saturation = Math.round(saturation * 100);
  lightness = Math.round(lightness * 100);
  document.getElementById("hue").value = hue;
  document.getElementById("saturation").value = saturation;
  document.getElementById("lightness").value = lightness;
  return hue, saturation, lightness;
}
function hslToRgb(hue, saturation, lightness) {
  saturation /= 100;
  lightness /= 100;

  if (saturation == 0) {
    red = green = blue = Math.round(lightness * 255); // achromatic
  } else {
    var hue2rgb = function hue2rgb(p, q, t) {
      if (t < 0) t += 1;
      if (t > 1) t -= 1;
      if (t < 1 / 6) return p + (q - p) * 6 * t;
      if (t < 1 / 2) return q;
      if (t < 2 / 3) return p + (q - p) * (2 / 3 - t) * 6;
      return p;
    };

    var q =
      lightness < 0.5
        ? lightness * (1 + saturation)
        : lightness + saturation - lightness * saturation;
    var p = 2 * lightness - q;
    var hhue = hue / 360;
    hhue.toFixed(4);
    red = hue2rgb(p, q, hhue + 1 / 3);
    green = hue2rgb(p, q, hhue);
    blue = hue2rgb(p, q, hhue - 1 / 3);
    red = Math.round(red * 255);
    green = Math.round(green * 255);
    blue = Math.round(blue * 255);
  }
  document.getElementById("red").value = red;
  document.getElementById("green").value = green;
  document.getElementById("blue").value = blue;

  document.getElementById("redvalue").innerHTML = red;
  document.getElementById("greenvalue").innerHTML = green;
  document.getElementById("bluevalue").innerHTML = blue;
  return red, green, blue;
}

function stringtorgb(str) {
  red_str = str[1] + str[2];
  green_str = str[3] + str[4];
  blue_str = str[5] + str[6];
  red = parseInt(red_str, 16);
  green = parseInt(green_str, 16);
  blue = parseInt(blue_str, 16);

  rgbToHsl(red, green, blue);
  output(red, green, blue, alpha, hue, saturation, lightness);
}
function checkDatabase(str) {
  var color_names = {
    AliceBlue: "#F0F8FF",
    AntiqueWhite: "#FAEBD7",
    Aqua: "#00FFFF",
    Aquamarine: "#7FFFD4",
    Azure: "#F0FFFF",
    Beige: "#F5F5DC",
    Bisque: "#FFE4C4",
    Black: "#000000",
    BlanchedAlmond: "#FFEBCD",
    Blue: "#0000FF",
    BlueViolet: "#8A2BE2",
    Brown: "#A52A2A",
    BurlyWood: "#DEB887",
    CadetBlue: "#5F9EA0",
    Chartreuse: "#7FFF00",
    Chocolate: "#D2691E",
    Coral: "#FF7F50",
    CornflowerBlue: "#6495ED",
    Cornsilk: "#FFF8DC",
    Crimson: "#DC143C",
    Cyan: "#00FFFF",
    DarkBlue: "#00008B",
    DarkCyan: "#008B8B",
    DarkGoldenRod: "#B8860B",
    DarkGray: "#A9A9A9",
    DarkGrey: "#A9A9A9",
    DarkGreen: "#006400",
    DarkKhaki: "#BDB76B",
    DarkMagenta: "#8B008B",
    DarkOliveGreen: "#556B2F",
    DarkOrange: "#FF8C00",
    DarkOrchid: "#9932CC",
    DarkRed: "#8B0000",
    DarkSalmon: "#E9967A",
    DarkSeaGreen: "#8FBC8F",
    DarkSlateBlue: "#483D8B",
    DarkSlateGray: "#2F4F4F",
    DarkSlateGrey: "#2F4F4F",
    DarkTurquoise: "#00CED1",
    DarkViolet: "#9400D3",
    DeepPink: "#FF1493",
    DeepSkyBlue: "#00BFFF",
    DimGray: "#696969",
    DimGrey: "#696969",
    DodgerBlue: "#1E90FF",
    FireBrick: "#B22222",
    FloralWhite: "#FFFAF0",
    ForestGreen: "#228B22",
    Fuchsia: "#FF00FF",
    Gainsboro: "#DCDCDC",
    GhostWhite: "#F8F8FF",
    Gold: "#FFD700",
    GoldenRod: "#DAA520",
    Gray: "#808080",
    Grey: "#808080",
    Green: "#008000",
    GreenYellow: "#ADFF2F",
    HoneyDew: "#F0FFF0",
    HotPink: "#FF69B4",
    IndianRed: "#CD5C5C",
    Indigo: "#4B0082",
    Ivory: "#FFFFF0",
    Khaki: "#F0E68C",
    Lavender: "#E6E6FA",
    LavenderBlush: "#FFF0F5",
    LawnGreen: "#7CFC00",
    LemonChiffon: "#FFFACD",
    LightBlue: "#ADD8E6",
    LightCoral: "#F08080",
    LightCyan: "#E0FFFF",
    LightGoldenRodYellow: "#FAFAD2",
    LightGray: "#D3D3D3",
    LightGrey: "#D3D3D3",
    LightGreen: "#90EE90",
    LightPink: "#FFB6C1",
    LightSalmon: "#FFA07A",
    LightSeaGreen: "#20B2AA",
    LightSkyBlue: "#87CEFA",
    LightSlateGray: "#778899",
    LightSlateGrey: "#778899",
    LightSteelBlue: "#B0C4DE",
    LightYellow: "#FFFFE0",
    Lime: "#00FF00",
    LimeGreen: "#32CD32",
    Linen: "#FAF0E6",
    Magenta: "#FF00FF",
    Maroon: "#800000",
    MediumAquaMarine: "#66CDAA",
    MediumBlue: "#0000CD",
    MediumOrchid: "#BA55D3",
    MediumPurple: "#9370DB",
    MediumSeaGreen: "#3CB371",
    MediumSlateBlue: "#7B68EE",
    MediumSpringGreen: "#00FA9A",
    MediumTurquoise: "#48D1CC",
    MediumVioletRed: "#C71585",
    MidnightBlue: "#191970",
    MintCream: "#F5FFFA",
    MistyRose: "#FFE4E1",
    Moccasin: "#FFE4B5",
    NavajoWhite: "#FFDEAD",
    Navy: "#000080",
    OldLace: "#FDF5E6",
    Olive: "#808000",
    OliveDrab: "#6B8E23",
    Orange: "#FFA500",
    OrangeRed: "#FF4500",
    Orchid: "#DA70D6",
    PaleGoldenRod: "#EEE8AA",
    PaleGreen: "#98FB98",
    PaleTurquoise: "#AFEEEE",
    PaleVioletRed: "#DB7093",
    PapayaWhip: "#FFEFD5",
    PeachPuff: "#FFDAB9",
    Peru: "#CD853F",
    Pink: "#FFC0CB",
    Plum: "#DDA0DD",
    PowderBlue: "#B0E0E6",
    Purple: "#800080",
    RebeccaPurple: "#663399",
    Red: "#FF0000",
    RosyBrown: "#BC8F8F",
    RoyalBlue: "#4169E1",
    SaddleBrown: "#8B4513",
    Salmon: "#FA8072",
    SandyBrown: "#F4A460",
    SeaGreen: "#2E8B57",
    SeaShell: "#FFF5EE",
    Sienna: "#A0522D",
    Silver: "#C0C0C0",
    SkyBlue: "#87CEEB",
    SlateBlue: "#6A5ACD",
    SlateGray: "#708090",
    SlateGrey: "#708090",
    Snow: "#FFFAFA",
    SpringGreen: "#00FF7F",
    SteelBlue: "#4682B4",
    Tan: "#D2B48C",
    Teal: "#008080",
    Thistle: "#D8BFD8",
    Tomato: "#FF6347",
    Turquoise: "#40E0D0",
    Violet: "#EE82EE",
    Wheat: "#F5DEB3",
    White: "#FFFFFF",
    WhiteSmoke: "#F5F5F5",
    Yellow: "#FFFF00",
    YellowGreen: "#9ACD32",
  };
  for (const [key, value] of Object.entries(color_names)) {
    if (str.toLowerCase() == key.toLowerCase()) {
      return value;
    }
  }
}
function codetoname(str) {
  var color_names = {
    AliceBlue: "#F0F8FF",
    AntiqueWhite: "#FAEBD7",
    Aqua: "#00FFFF",
    Aquamarine: "#7FFFD4",
    Azure: "#F0FFFF",
    Beige: "#F5F5DC",
    Bisque: "#FFE4C4",
    Black: "#000000",
    BlanchedAlmond: "#FFEBCD",
    Blue: "#0000FF",
    BlueViolet: "#8A2BE2",
    Brown: "#A52A2A",
    BurlyWood: "#DEB887",
    CadetBlue: "#5F9EA0",
    Chartreuse: "#7FFF00",
    Chocolate: "#D2691E",
    Coral: "#FF7F50",
    CornflowerBlue: "#6495ED",
    Cornsilk: "#FFF8DC",
    Crimson: "#DC143C",
    Cyan: "#00FFFF",
    DarkBlue: "#00008B",
    DarkCyan: "#008B8B",
    DarkGoldenRod: "#B8860B",
    DarkGray: "#A9A9A9",
    DarkGrey: "#A9A9A9",
    DarkGreen: "#006400",
    DarkKhaki: "#BDB76B",
    DarkMagenta: "#8B008B",
    DarkOliveGreen: "#556B2F",
    DarkOrange: "#FF8C00",
    DarkOrchid: "#9932CC",
    DarkRed: "#8B0000",
    DarkSalmon: "#E9967A",
    DarkSeaGreen: "#8FBC8F",
    DarkSlateBlue: "#483D8B",
    DarkSlateGray: "#2F4F4F",
    DarkSlateGrey: "#2F4F4F",
    DarkTurquoise: "#00CED1",
    DarkViolet: "#9400D3",
    DeepPink: "#FF1493",
    DeepSkyBlue: "#00BFFF",
    DimGray: "#696969",
    DimGrey: "#696969",
    DodgerBlue: "#1E90FF",
    FireBrick: "#B22222",
    FloralWhite: "#FFFAF0",
    ForestGreen: "#228B22",
    Fuchsia: "#FF00FF",
    Gainsboro: "#DCDCDC",
    GhostWhite: "#F8F8FF",
    Gold: "#FFD700",
    GoldenRod: "#DAA520",
    Gray: "#808080",
    Grey: "#808080",
    Green: "#008000",
    GreenYellow: "#ADFF2F",
    HoneyDew: "#F0FFF0",
    HotPink: "#FF69B4",
    IndianRed: "#CD5C5C",
    Indigo: "#4B0082",
    Ivory: "#FFFFF0",
    Khaki: "#F0E68C",
    Lavender: "#E6E6FA",
    LavenderBlush: "#FFF0F5",
    LawnGreen: "#7CFC00",
    LemonChiffon: "#FFFACD",
    LightBlue: "#ADD8E6",
    LightCoral: "#F08080",
    LightCyan: "#E0FFFF",
    LightGoldenRodYellow: "#FAFAD2",
    LightGray: "#D3D3D3",
    LightGrey: "#D3D3D3",
    LightGreen: "#90EE90",
    LightPink: "#FFB6C1",
    LightSalmon: "#FFA07A",
    LightSeaGreen: "#20B2AA",
    LightSkyBlue: "#87CEFA",
    LightSlateGray: "#778899",
    LightSlateGrey: "#778899",
    LightSteelBlue: "#B0C4DE",
    LightYellow: "#FFFFE0",
    Lime: "#00FF00",
    LimeGreen: "#32CD32",
    Linen: "#FAF0E6",
    Magenta: "#FF00FF",
    Maroon: "#800000",
    MediumAquaMarine: "#66CDAA",
    MediumBlue: "#0000CD",
    MediumOrchid: "#BA55D3",
    MediumPurple: "#9370DB",
    MediumSeaGreen: "#3CB371",
    MediumSlateBlue: "#7B68EE",
    MediumSpringGreen: "#00FA9A",
    MediumTurquoise: "#48D1CC",
    MediumVioletRed: "#C71585",
    MidnightBlue: "#191970",
    MintCream: "#F5FFFA",
    MistyRose: "#FFE4E1",
    Moccasin: "#FFE4B5",
    NavajoWhite: "#FFDEAD",
    Navy: "#000080",
    OldLace: "#FDF5E6",
    Olive: "#808000",
    OliveDrab: "#6B8E23",
    Orange: "#FFA500",
    OrangeRed: "#FF4500",
    Orchid: "#DA70D6",
    PaleGoldenRod: "#EEE8AA",
    PaleGreen: "#98FB98",
    PaleTurquoise: "#AFEEEE",
    PaleVioletRed: "#DB7093",
    PapayaWhip: "#FFEFD5",
    PeachPuff: "#FFDAB9",
    Peru: "#CD853F",
    Pink: "#FFC0CB",
    Plum: "#DDA0DD",
    PowderBlue: "#B0E0E6",
    Purple: "#800080",
    RebeccaPurple: "#663399",
    Red: "#FF0000",
    RosyBrown: "#BC8F8F",
    RoyalBlue: "#4169E1",
    SaddleBrown: "#8B4513",
    Salmon: "#FA8072",
    SandyBrown: "#F4A460",
    SeaGreen: "#2E8B57",
    SeaShell: "#FFF5EE",
    Sienna: "#A0522D",
    Silver: "#C0C0C0",
    SkyBlue: "#87CEEB",
    SlateBlue: "#6A5ACD",
    SlateGray: "#708090",
    SlateGrey: "#708090",
    Snow: "#FFFAFA",
    SpringGreen: "#00FF7F",
    SteelBlue: "#4682B4",
    Tan: "#D2B48C",
    Teal: "#008080",
    Thistle: "#D8BFD8",
    Tomato: "#FF6347",
    Turquoise: "#40E0D0",
    Violet: "#EE82EE",
    Wheat: "#F5DEB3",
    White: "#FFFFFF",
    WhiteSmoke: "#F5F5F5",
    Yellow: "#FFFF00",
    YellowGreen: "#9ACD32",
  };
  for (const [key, value] of Object.entries(color_names)) {
    if (str.toLowerCase() == value.toLowerCase()) {
      return key;
    }
  }
}
function searchfor() {
  var color = document.getElementById("myInput").value;
  var checked_color = checkDatabase(color);

  stringtorgb(checked_color);
}

function output(red, green, blue, alpha, hue, saturation, lightness) {
  document.getElementById("redvalue").innerHTML = red;
  document.getElementById("greenvalue").innerHTML = green;
  document.getElementById("bluevalue").innerHTML = blue;
  document.getElementById("alphavalue").innerHTML = alpha * 100 + "%";
  document.getElementById("huevalue").innerHTML = hue;
  document.getElementById("saturationvalue").innerHTML = saturation + "%";
  document.getElementById("lightnessvalue").innerHTML = lightness + "%";

  hexred = (+red).toString(16);
  hexgreen = (+green).toString(16);
  hexblue = (+blue).toString(16);

  codered = hexred;
  codegreen = hexgreen;
  codeblue = hexblue;

  if (codered.length == 1) {
    codered = codered[0] + codered[0];
  }
  if (codegreen.length == 1) {
    codegreen = codegreen[0] + codegreen[0];
  }
  if (codeblue.length == 1) {
    codeblue = codeblue[0] + codeblue[0];
  }

  colorname = "#" + codered + codegreen + codeblue;

  if (hexred.length == 1) {
    hexred = hexred[0] + hexred[0];
  }
  if (hexgreen.length == 1) {
    hexgreen = hexgreen[0] + hexgreen[0];
  }
  if (hexblue.length == 1) {
    hexblue = hexblue[0] + hexblue[0];
  }
  if (
    hexred[0] == hexred[1] &&
    hexgreen[0] == hexgreen[1] &&
    hexblue[0] == hexblue[1]
  ) {
    hexred = hexred[0];
    hexgreen = hexgreen[0];
    hexblue = hexblue[0];
  }

  hexall = "#" + hexred + hexgreen + hexblue;
  if (codetoname(colorname)) {
    colorname = codetoname(colorname);
  } else {
    colorname = hexall;
  }

  document.getElementById("namevalue").innerHTML = "Name: " + colorname;
  document.getElementById("codevalue").innerHTML = "Code: " + hexall;
  document.getElementById("rgbvalue").innerHTML =
    "rgba(" + red + ", " + green + ", " + blue + ", " + alpha + ")";
  document.getElementById("hslvalue").innerHTML =
    "hsl(" + hue + ", " + saturation + ", " + lightness + ")";

  var display = document.getElementById("display");
  display.style.background =
    "rgba(" + red + ", " + green + ", " + blue + ", " + alpha + ")";
}
function EnterPressed(event) {
  var x = event.keyCode;
  if (x == 13) {
    searchfor();
  }
}

var input = document.querySelectorAll("input");

for (var i = 0; i < input.length; i++) {
  if (i == 1 || i == 2 || i == 3) {
    input[i].addEventListener("input", function () {
      var red = document.getElementById("red").value,
        green = document.getElementById("green").value,
        blue = document.getElementById("blue").value;
      alpha = document.getElementById("alpha").value;
      hue = document.getElementById("hue").value;
      saturation = document.getElementById("saturation").value;
      lightness = document.getElementById("lightness").value;

      rgbToHsl(red, green, blue);
      output(red, green, blue, alpha, hue, saturation, lightness);
    });
  }
  if (i == 4) {
    input[i].addEventListener("input", function () {
      var red = document.getElementById("red").value,
        green = document.getElementById("green").value,
        blue = document.getElementById("blue").value;
      alpha = document.getElementById("alpha").value;
      hue = document.getElementById("hue").value;
      saturation = document.getElementById("saturation").value;
      lightness = document.getElementById("lightness").value;

      output(red, green, blue, alpha, hue, saturation, lightness);
    });
  }
  if (i == 5 || i == 6 || i == 7) {
    input[i].addEventListener("input", function () {
      var red = document.getElementById("red").value,
        green = document.getElementById("green").value,
        blue = document.getElementById("blue").value;
      alpha = document.getElementById("alpha").value;
      hue = document.getElementById("hue").value;
      saturation = document.getElementById("saturation").value;
      lightness = document.getElementById("lightness").value;

      hslToRgb(hue, saturation, lightness);
      rgbToHsl(red, green, blue);
      output(red, green, blue, alpha, hue, saturation, lightness);
    });
  }
}

function changecolor(red, green, blue, alpha, hue, saturation, lightness) {
  output(red, green, blue, alpha, hue, saturation, lightness);
  document.getElementById("red").value = red;
  document.getElementById("green").value = green;
  document.getElementById("blue").value = blue;

  document.getElementById("hue").value = hue;
  document.getElementById("saturation").value = saturation;
  document.getElementById("lightness").value = lightness;
}
