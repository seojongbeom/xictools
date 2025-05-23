<?xml version="1.0" encoding="ISO-8859-1"?>

<!--
  $Id: device.xml,v 1.15 2016/09/26 18:54:38 stevew Exp $

  Configuration code for amds Verilog-AMS model translator.
  Whiteley Research Inc. (wrcad.com). 

This must match the Makefile.
SyntaxLevel 0
-->

<!DOCTYPE admst SYSTEM "admst.dtd">
<admst version="2.3.0"
  xmlns:admst="http://mot-adms.sourceforge.net/xml-files/admst">

<!--
This file must be edited by the user before a device is compiled with
the adms compiler (the Makefile does this).  The "@xxx@" tokens found
below must be replaced with suitable text, as described.

1.  The module name (@MODULE@).
This is a short, lower-case, single word which is used to prefix files
and internal variables for this device.  It can be the same as the top
module name in the Verilog source, or can be completely different.  If
you plan to keep your loadable module files in the same directory, it
must be unique.  It will be the base name of the loadable module
produced.

2.  The model name (@MODELNAME@).
This is the name of the model by which the device model may be
accessed in WRspice.  Typically, the device can be accessed in either
of two ways:  through a unique nodel name, or via a standard modelname
and unique level number.  For example, in a user's SPICE deck one
could have equivalently
  .model mymod nmos level=unique_level_num ...
  .model mymod unique_model_name ...

3.  The device key letter (@KEY@).
This specifies the type of device to WRspice.  It must be a single
lower-case alphabetic character, from among the choices below.

The acceptable key letters are:
  b : josephson junction
  c : capacitor
  d : diode
  j : junction fet
  l : inductor
  m : mos transistor
  n : unassigned
  o : transmission line
  p : unassigned
  q : bipolar transistor
  r : resistor
  s : voltage-controlled switch
  t : transmission line
  u : lumped-element (urc) transmission line
  w : current-controlled switch
  y : unassigned
  z : mesfet

In particular, letters corresponding to source devices, subcircuits,
and mutual inductors are not accepted.  The letter must correspond to
the type of device being compiled.  You can use the "unassigned"
letters if the device does not fit an existing category.

4.  The model level (@LEVEL@).
This specifies the "level" parameter value used to specify the device
in a .model line.  This can be any positive value, but generally
should be chosen so as not to conflict with other models.

If two or more internal or dynamically loaded devices have the same
key letter and model level, the one loaded first will have precedence. 
Thus, it is not possible to override an internal device model, or a
previously loaded module.  However, if a subsequently loaded module
has the same full path string as a module loaded earlier, the earlier
loaded module will be replaced.

It is also possible to resolve the model by name, see MODELNAME above.

5, The WRspice release numbers (@VERSION@, @MAJOR@ and @MINOR@).  If
the WRspice release number is 4.1.6, for example, VERSION would be
"4.1.6", MAJOR would be "4.1", and MINOR would be "6".

6.  The @ADD_M@ can be either of "yes" or "no".  If yes, and the
device does not have an instance parameter named "m", then a
real-valued parameter of this name will be added. The default value is
1.0, and the parameter will multiply the contributions from the device
model, effectively scaling the device count.  For example, giving
'm=2' as a device instance parameter is equivalent to specifying two
identical, parallel devices.

7.  The @PREDICTOR@ can be either "yes" or "no".  When set to yes, a
linear predictor is applied to the voltages of each device pin on the
first solution at a new time step.  Otherwise, the initial voltages
are simply the final value from the previous time step.  Semiconductor
devices tend to benefit (require fewer transient iterations) from
having the predictor, passive devices, unless nonlinear, not so much. 
The predictor may affect integration accuracy of reactive devices, in
particular this is not recommended for Josephson junctions.

8.  The @LIMITING@ can be either "yes" or "no".  When set to yes and
@PREDICTOR@ is also set to yes, a limiting algorithm is used on every
device pin during transient analysis.  This is probably required for
convergence of semiconductor device models that contain p/n or
Schottky junctions.  One can turn this off for non-semiconductor
devices.

9.  The @FLAGS@ will be added to the dv_flags member of the device
structure.  See the Makefile description.  This is almost always
empty.

10.  The @HEADER@ can be either "yes" or "no".  When set to yes, a
header file will be included in all of the C++ files, through a call
added to the module include file.  The file will be named
(MODULE)extra.h, where (MODULE) is the short module abbreviation
mentioned above.  The user must provide this include file.  The
purpose is to facilitate advanced users adding code to the C++ module
files.
-->

  <admst:variable name="package_module"         value="@MODULE@"/>
  <admst:variable name="package_modelname"      value="@MODELNAME@"/>
  <admst:variable name="package_devkey"         value="@KEY@"/>
  <admst:variable name="package_level"          value="@LEVEL@"/>
  <admst:variable name="package_major"          value="@MAJOR@"/>
  <admst:variable name="package_minor"          value="@MINOR@"/>
  <admst:variable name="package_add_m"          value="@ADD_M@"/>
  <admst:variable name="package_predictor"      value="@PREDICTOR@"/>
  <admst:variable name="package_limiting"       value="@LIMITING@"/>
  <admst:variable name="package_flags"          value="@FLAGS@"/>
  <admst:variable name="package_header"         value="@HEADER@"/>

  <admst:value-to select="/simulator/package_name" value="wrspice"/>
  <admst:value-to select="/simulator/package_tarname" value="wrspice"/>
  <admst:value-to select="/simulator/package_version" value="@VERSION@"/>
  <admst:value-to select="/simulator/package_string" value="wrspice @VERSION@"/>
  <admst:value-to select="/simulator/package_bugreport"
    value="wrspice@wrcad.com"/>
</admst>

