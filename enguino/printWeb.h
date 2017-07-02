void printHomePage() {
  print_P(F(
  "<!DOCTYPE html>\n"
  "<html>\n"
    "<head>\n"
      "<title>Enguino</title>\n"
      "<meta name='apple-mobile-web-app-capable' content='yes'>\n"      
      "<meta name='mobile-web-app-capable' content='yes'>\n"      
      "<style>\n"
        ".segment { stroke:gray; stroke-width:20; }\n"
        ".rectgauge  {  fill:none; stroke:black; stroke-width:40; }\n"
        ".roundgauge {  fill:none; stroke:black; }\n"
        ".label  { fill:dimgrey; text-anchor:middle; font-size:500px; }\n"
        ".value  { fill:black; text-anchor:middle; font-size:500px; }\n"
        ".number { fill:dimgrey; text-anchor:start; font-size:300px; alignment-baseline:central; }\n"
        ".mnumber { fill:dimgrey; text-anchor:middle; font-size:300px; alignment-baseline:central; }\n"
        ".unit   { fill:dimgrey; text-anchor:middle; font-size:300px; }\n"
        ".abutton { fill:lightgrey; stroke:black; stroke-width:40; }\n"
        ".indicator { fill:black }\n"
      "</style>\n"
      "<script type='text/javascript'>\n"
        "function ajax(u) {\n"
          "var xhttp = new XMLHttpRequest();\n"
          "xhttp.onreadystatechange = function() {\n"
            "if (this.readyState == 4 && this.status == 200) {\n"
              "document.getElementById('dyn').innerHTML =\n"
              "this.responseText;\n"
            "}\n"
          "};\n"
          "xhttp.open('GET', u, true);\n"
          "xhttp.send();\n"
        "}\n"
        "setInterval(function(){ajax('d')}, 1000);\n"
      "</script>\n"
    "</head>\n"
    "<body>\n"
    "<svg viewBox='0 0 13330 10000' style='display:block; position:absolute; top:5%; left:5%; width:90%; height:90%;'>\n"
#ifdef BOUNDING_BOX
    "<rect x='1' y='1' width='13327' height='9998' fill='none' stroke='red'/>\n"
#endif
    "<defs>\n"
    "<g id='hmark'>\n"
    "<path d='M0 310 l-50 -50 v-520 l50 -50 l50 50 v520 Z' class='indicator'>\n"
    "</g>\n"
    "<g id='xmark'>\n"
    "<path d='M0 220 l-150 150 h300 Z ' class='indicator'>\n"
    "</g>\n"
    "<g id='vmark'>\n"
    "<path d='M310 0 l-50 -50 h-520 l-50 50 l50 50 h520 Z' class='indicator'>\n"
    "</g>\n"
    "</defs>\n"
    "<g id='dyn'></g>\n"
    "</svg>\n"
    "</body>\n"
  "</html>\n"
  ));
}

void printSetupPage() {
  print_P(F(   
    "<!DOCTYPE html>\n"
    "<html>\n"
      "<style>\n"
        "form {\n"
          "border: solid gray;\n"
          "border-radius: 1em;\n"
          "padding: 1em;\n"
          "position: absolute;\n"
          "top: 50%;\n"
          "left: 50%;\n"
          "margin-right: -50%;\n"
          "transform: translate(-50%, -50%);\n"
        "}\n"
        "input {\n"
          "margin-right: 1em;\n"
        "}\n"
      "</style>\n"
      "<form>\n"
        "<input type='radio' name='x' value='a' checked/>Add fuel<br>\n"
        "<input type='radio' name='x' value='f'/>Set fuel capacity<br>\n"
        "<input type='radio' name='x' value='h'/>Set hobbs<br>\n"
        "<input type='radio' name='x' value='k'/>Set fuel flow k<br>\n"
        "<br>\n"
        "<input type='number' name='n' pattern='[0-9]*'/>\n"
        "<input type='submit'/><br>\n"
        "<br>\n"
        "<input type='submit' value='Tanks Filled' onClick=\"javascript:location.href = '/fill';\"/>\n"
        "<input type='submit' value='Cancel' style='float:right;' onClick=\"javascript:location.href = '/';\"/\n"
      "</form>\n"
    "</html>\n"
  ));
}
    
