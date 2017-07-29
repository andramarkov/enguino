// Uncommenting the following line shows a box around each instrumment and around the viewable area of the page. Use to help arrange gauges.
// #define BOUNDING_BOX

#define TACH_DIVIDER 4

#define DEFAULT_K_FACTOR (68000L / 40)  // for fuel flow transducer

// Exceed any of these and engine will be considered 'running'. Hobbs time will accumulate and engine alerts will appear. A 0 value will cause that sensor to be ignored.
#define RUN_VOLT 130
#define RUN_OILP 30
#define RUN_TACH 200

// Sensor defintions and scaling
// -----------------------------
// The sensors are scaled using the following formula, are scaled as follow: y = factor * (adc + offset).
// All of these numbers must be integers. Factors are represented as a ratio with an integer numerator and a denominator of 8192.
// Some numeric values are multipled by 10 and then have a decimal point added when displayed. 
// SCALE(1.) returns the raw values (ADC, RPM's). SCALE(range/full_scale) returns a value from 0 to range.
// The gauge pointers vary from 0 to 1000. Use GMIN() and GRNG to set the graphs b and m values based on lowest input and input range (hi-low) respectively. 
// Manifold pressure sensor = P(inch) = V(full) * 32.811 + 3.117 or V = (P-3.117)/32.811

//   sensor-type    range   
// --------------  --------
// st_r240to33     0 - 1000   proportional on resistance of sensor forming resistor divider
// st_v240to33     0 - 1000   proportional on voltage of sensor forming resistor divider
// st_thermistorC  0 - 1500   degrees C. in tenths
// st_thermistorF 32 - 2732   degrees F. in tenths
// st_volts        0 - 1000   5 mV/per count
// st_k_type_tcC   0 - 4000   0-1000 degrees C. in quarters
// st_j_type_tcC   0 - 4000   0-1000 degrees C. in quarters
// st_k_type_tcF   0 - 4000   32-1832 degrees F. in quarters
// st_j_type_tcF   0 - 4000   32-1832 degrees F. in quarters
// st_unit                    unit values, RPM, fuel flow, hobbs

//                      sensor-type,  pin, decimal, voffset,         vfactor,            goffset,          gfactor,lowWarning,lowCaution,highCaution,highWarning
const Sensor oilpS =  { st_v240to33,    1,       0,       0,     SCALE(.100),                  0,        SCALE(1.),        25,       55,      9999,        95 }; 
const Sensor oiltS =  { st_thermistorF, 2,       0,       0,     SCALE(.100),        GMIN(50*10),      GRNG(200*10),       -1,      140,      9999,       250 };
const Sensor voltS =  { st_volts,       0,       1,       0,     SCALE(.200),    GMIN(100*fromV),    GRNG(60*fromV),      110,      130,      9999,       160 };
const Sensor fuelpS = { st_v240to33,    3,       1,       0,     SCALE(.150),                  0,  SCALE(150./100.),        5,       20,        60,        80 };
const Sensor fuellS = { st_v240to33,  DUAL(4),   1,       0,     SCALE(.160),                  0,         SCALE(1.),       25,       50,      9999,       999 };    
const Sensor tachS =  { st_unit,    TACH_SENSOR, 0,       0,       SCALE(1.),            GMIN(0),        GRNG(3000),       -1,      500,      9999,      2700 };
const Sensor mapS =   { st_volts,       8,       1,     102,   SCALE(.32811),          GMIN(210),GRNG(1000*25/32.811),     -1,       -1,      9999,      9999 }; 
const Sensor chtS =   { st_k_type_tcF, 16,       0,       0,      SCALE(.25),        GMIN(100*4),       GRNG(400*4),       -1,      150,       400,       500 };  
const Sensor egtS =   { st_k_type_tcF, 20,       0,       0,      SCALE(.25),       GMIN(1000*4),       GRNG(600*4),       -1,       -1,      9999,      9999 };
const Sensor fuelfS = { st_unit,   FUELF_SENSOR, 1,       0,       SCALE(1.),            GMIN(0),        GRNG(150),        -1,       -1,      9999,      9999 };
const Sensor fuelrS = { st_unit,   FUELR_SENSOR, 1,       0,       SCALE(1.),            GMIN(0),        GRNG(400),        -1,       -1,      9999,      9999 };
const Sensor hobbsS = { st_unit,   HOBBS_SENSOR, 1,       0,       SCALE(1.),            GMIN(0),       GRNG(1000),        -1,       -1,      9999,      9999 };

// Label and gradations 
// --------------------
string    oilpLV[] =  {     "80",            "60",           "40",           "20"  };
const int oilpLP[] =  { VSEG(80./100.),  VSEG(60./100.), VSEG(40./100.), VSEG(20./100.) };
string    oiltLV[] =  {     "200",           "150",          "100" };
const int oiltLP[] =  { VSEG(150./200.), VSEG(100./200.), VSEG(50./200.) };     // offset and range offset by 50 deg-F
string    voltLV[] =  {    "14",        "12"  };
const int voltLP[] =  { VSEG(4./6.), VSEG(2./6.) };                             // offset and range offset by 10 volts
string   fuelpLV[] =   {     "8",           "6",          "4",          "2" };
const int fuelpLP[] =  { VSEG(8./10.),  VSEG(6./10.), VSEG(4./10.), VSEG(2./10.) };
string    fuellLV[] =  {     "15",          "10",          "5",          "2.5" };
const int fuellLP[] =  { VSEG(15./16.), VSEG(10./16.), VSEG(5./16.), VSEG(2.5/16.) };
string    chtLV[] =  {     "200&deg;F",     "300&deg;F",     "400&deg;F" };
const int chtLP[] =  { HSEG(100./400.), HSEG(200./400.), HSEG(300./400.) };    // offset and range offset by 100 deg-F
string    egtLV[] =  {    "1150&deg;",     "1300&deg;",     "1450&deg;" };
const int egtLP[] =  { HSEG(150./600.), HSEG(300./600.), HSEG(450./600.) };    // offset and range offset by 1000 deg-F

// Color regions
// -------------
string oilpRC[] = { red,            yellow,         green,          red     };
int    oilpRP[] = { VSEG(25./100.), VSEG(55./100.), VSEG(95./100.), VSEG(1) };
string oiltRC[] = { yellow,         green,           red     };
int    oiltRP[] = { VSEG(40./200.), VSEG(196./200.), VSEG(1) };     // offset and range offset by 50 deg-F
string voltRC[] = { red,         yellow,      green,       yellow,       red     };
int    voltRP[] = { VSEG(1./6.), VSEG(3./6.), VSEG(5./6.), VSEG(5.9/6.), VSEG(1) };      // offset and range offset by 10 volts
string fuelpRC[] = { red,          yellow,       green,        yellow,       red     };
int    fuelpRP[] = { VSEG(.5/10.), VSEG(2./10.), VSEG(6./10.), VSEG(8./10.), VSEG(1) };
string fuellRC[] = { red,           yellow,       green   };
int    fuellRP[] = { VSEG(2.5/16.), VSEG(5./16.), VSEG(1) };
string tachRC[] = { yellow,              green,                red       };
int    tachRP[] = { ARCX(500./3000.),    ARCX(2700./3000.),    ARCX(1),       // x  
                    ARCY(500./3000.),    ARCY(2700./3000.),    ARCY(1),       // y 
                    0,                   0,                    0         };   // arc segmenet is > 180 degrees
string mapRC[] = { green    };
int    mapRP[] = { ARCX(1),        // x
                   ARCY(1),        // y
                   1      };       // arc segmenet is > 180 degrees
string chtRC[] = { yellow,         green,           yellow,          red     };
int    chtRP[] = { HSEG(50./400.), HSEG(300./400.), HSEG(395./400.), HSEG(1) };     // offset and range offset by 100 deg-F

// Gauge layout for screen
// -----------------------
#define bank 3500   // bank of misc vertical gauges
const Gauge gauges[] = {
  //  x,      y,  style,     label1, label2, units,    labVal,   labPt,        num,  regClr,   regPt,        num,  sensor
  {bank+0,    0,  gs_vert,   "OIL",  "PRES", "psi",    oilpLV,  oilpLP,  N(oilpLV),  oilpRC,  oilpRP,  N(oilpRC),  &oilpS},
  {bank+1750, 0,  gs_vert,   "OIL",  "TEMP", "&deg;F", oiltLV,  oiltLP,  N(oiltLV),  oiltRC,  oiltRP,  N(oiltRC),  &oiltS},
  {bank+3500, 0,  gs_vert,   "",     "VOLT", "volt",   voltLV,  voltLP,  N(voltLV),  voltRC,  voltRP,  N(voltRC),  &voltS},
  {bank+5250, 0,  gs_vert,   "FUEL", "PRES", "psi",    fuelpLV, fuelpLP, N(fuelpLV), fuelpRC, fuelpRP, N(fuelpRC), &fuelpS},
  {bank+7000, 0,  gs_pair,   "FUEL", "",     "gal",    fuellLV, fuellLP, N(fuellLV), fuellRC, fuellRP, N(fuellRC), &fuellS}, 
  {100,       0,  gs_round,  "TACH", "",     "rpm",    0,       0,       0,          tachRC,  tachRP,  N(tachRC),  &tachS},
  {100,    3200,  gs_round,  "MP",   "",     "in-hg",  0,       0,       0,          mapRC,   mapRP,   N(mapRC),   &mapS},
  {2950,    6150, gs_horiz,  "CHT",  "",     "",       chtLV,   chtLP,   N(chtLV),   chtRC,   chtRP,   N(chtRC),   &chtS},
  {2950,    6150, gs_egt,    "EGT",  "",     "",       egtLV,   egtLP,   N(egtLV),   0,       0,       0,          &egtS},
  {800,     6650, gs_infobox,"",     "",     "",       0,       0,       0,          0,       0,       0,          0}
};

// Guage layout for aux display
// ----------------------------
// Layout is text, top-sensor, bottom-sensor. Sensor value is displayed in the top line if text is blank, otherwise top sensor is used to show warning/caution and low/high on top line
AuxDisplay auxDisplay[] = {
  AUX(H,o,b,b, 0,       &hobbsS),  
  AUX(b,A,t, , &voltS,  &voltS),  
  AUX( , , , , &tachS,  &fuellS),
  AUX(O,P, , , &oilpS,  &oilpS),  
  AUX(O,t, , , &oiltS,  &oiltS),  
  AUX(F,P, , , &fuelpS, &fuelpS),  
  AUX(A,L,t, , &voltS,  &voltS),  
};

// number of pages shown on startup
#define AUX_STARTUP_PAGES 2

