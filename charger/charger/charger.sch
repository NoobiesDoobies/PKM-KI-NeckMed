<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.2">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="24" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="TP4056">
<packages>
<package name="TP4056">
<wire x1="0" y1="0" x2="28" y2="0" width="0.127" layer="21"/>
<wire x1="28" y1="0" x2="28" y2="17.2" width="0.127" layer="21"/>
<wire x1="28" y1="17.2" x2="0" y2="17.2" width="0.127" layer="21"/>
<wire x1="0" y1="17.2" x2="0" y2="0" width="0.127" layer="21"/>
<text x="11" y="8" size="1.27" layer="21">TP4056</text>
<pad name="-IN" x="2.5" y="1.6" drill="1.143" shape="square"/>
<pad name="+IN" x="2.5" y="15.6" drill="1.143" shape="square"/>
<pad name="OUT-" x="25.5" y="1.6" drill="1.143" shape="square"/>
<pad name="OUT+" x="25.5" y="15.6" drill="1.143" shape="square"/>
<pad name="B-" x="25.5" y="4.6" drill="1.143" shape="square"/>
<pad name="B+" x="25.5" y="12.6" drill="1.143" shape="square"/>
</package>
</packages>
<symbols>
<symbol name="TP4056">
<pin name="+IN" x="-17.78" y="7.62" length="middle"/>
<pin name="-IN" x="-17.78" y="-7.62" length="middle"/>
<pin name="OUT-" x="20.32" y="-7.62" length="middle" rot="R180"/>
<pin name="OUT+" x="20.32" y="7.62" length="middle" rot="R180"/>
<pin name="B-" x="20.32" y="-2.54" length="middle" rot="R180"/>
<pin name="B+" x="20.32" y="2.54" length="middle" rot="R180"/>
<wire x1="-12.7" y1="10.16" x2="-12.7" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-10.16" x2="15.24" y2="-10.16" width="0.254" layer="94"/>
<wire x1="15.24" y1="-10.16" x2="15.24" y2="10.16" width="0.254" layer="94"/>
<wire x1="15.24" y1="10.16" x2="-12.7" y2="10.16" width="0.254" layer="94"/>
<text x="-2.54" y="0" size="1.27" layer="94">TP4056</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="TP4056">
<gates>
<gate name="G$1" symbol="TP4056" x="12.7" y="10.16"/>
</gates>
<devices>
<device name="" package="TP4056">
<connects>
<connect gate="G$1" pin="+IN" pad="+IN"/>
<connect gate="G$1" pin="-IN" pad="-IN"/>
<connect gate="G$1" pin="B+" pad="B+"/>
<connect gate="G$1" pin="B-" pad="B-"/>
<connect gate="G$1" pin="OUT+" pad="OUT+"/>
<connect gate="G$1" pin="OUT-" pad="OUT-"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="B2B-XH-A">
<packages>
<package name="JST_B2B-XH-A">
<wire x1="3.7" y1="2.875" x2="3.7" y2="-2.875" width="0.127" layer="51"/>
<wire x1="3.7" y1="-2.875" x2="-3.7" y2="-2.875" width="0.127" layer="51"/>
<wire x1="-3.7" y1="-2.875" x2="-3.7" y2="2.875" width="0.127" layer="51"/>
<wire x1="-3.7" y1="2.875" x2="3.7" y2="2.875" width="0.127" layer="51"/>
<circle x="4.44" y="-0.525" radius="0.1" width="0.2" layer="51"/>
<wire x1="3.7" y1="2.875" x2="3.7" y2="-2.875" width="0.127" layer="21"/>
<wire x1="3.7" y1="-2.875" x2="-3.7" y2="-2.875" width="0.127" layer="21"/>
<wire x1="-3.7" y1="-2.875" x2="-3.7" y2="2.875" width="0.127" layer="21"/>
<wire x1="-3.7" y1="2.875" x2="3.7" y2="2.875" width="0.127" layer="21"/>
<wire x1="-3.95" y1="3.125" x2="-3.95" y2="-3.125" width="0.05" layer="39"/>
<wire x1="-3.95" y1="-3.125" x2="3.95" y2="-3.125" width="0.05" layer="39"/>
<wire x1="3.95" y1="-3.125" x2="3.95" y2="3.125" width="0.05" layer="39"/>
<wire x1="3.95" y1="3.125" x2="-3.95" y2="3.125" width="0.05" layer="39"/>
<circle x="4.44" y="-0.525" radius="0.1" width="0.2" layer="21"/>
<text x="-3.95" y="4.125" size="1.27" layer="25">&gt;NAME</text>
<text x="-3.95" y="-4.125" size="1.27" layer="27" align="top-left">&gt;VALUE</text>
<pad name="2" x="-1.25" y="-0.525" drill="1.05" shape="square"/>
<pad name="1" x="1.25" y="-0.525" drill="1.05" shape="square"/>
</package>
</packages>
<symbols>
<symbol name="B2B-XH-A">
<wire x1="-3.81" y1="3.81" x2="-2.54" y2="5.08" width="0.254" layer="94"/>
<wire x1="-3.81" y1="3.81" x2="-3.81" y2="-1.27" width="0.254" layer="94"/>
<wire x1="-3.81" y1="-1.27" x2="-2.54" y2="-2.54" width="0.254" layer="94"/>
<wire x1="-2.54" y1="-2.54" x2="3.81" y2="-2.54" width="0.254" layer="94"/>
<wire x1="3.81" y1="-2.54" x2="3.81" y2="5.08" width="0.254" layer="94"/>
<wire x1="3.81" y1="5.08" x2="-2.54" y2="5.08" width="0.254" layer="94"/>
<text x="-2.54" y="6.35" size="1.778" layer="95">&gt;NAME</text>
<text x="-2.54" y="-5.08" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-3.175" y1="2.2225" x2="-1.5875" y2="2.8575" layer="94"/>
<rectangle x1="-3.175" y1="-0.3175" x2="-1.5875" y2="0.3175" layer="94"/>
<pin name="1" x="-7.62" y="2.54" length="middle" direction="pas"/>
<pin name="2" x="-7.62" y="0" length="middle" direction="pas"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="B2B-XH-A" prefix="J">
<description> &lt;a href="https://pricing.snapeda.com/parts/B2B-XH-A/JST%20Sales/view-part?ref=eda"&gt;Check availability&lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="B2B-XH-A" x="0" y="0"/>
</gates>
<devices>
<device name="" package="JST_B2B-XH-A">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="AVAILABILITY" value="In Stock"/>
<attribute name="CHECK_PRICES" value="https://www.snapeda.com/parts/B2B-XH-A/JST+Sales+America+Inc./view-part/?ref=eda"/>
<attribute name="DESCRIPTION" value=" Connector Header Through Hole 2 position 0.098 (2.50mm) "/>
<attribute name="MF" value="JST Sales"/>
<attribute name="MP" value="B2B-XH-A"/>
<attribute name="PACKAGE" value="None"/>
<attribute name="PRICE" value="None"/>
<attribute name="PURCHASE-URL" value="https://www.snapeda.com/api/url_track_click_mouser/?unipart_id=552747&amp;manufacturer=JST Sales&amp;part_name=B2B-XH-A&amp;search_term=b2bxh-a"/>
<attribute name="SNAPEDA_LINK" value="https://www.snapeda.com/parts/B2B-XH-A/JST+Sales+America+Inc./view-part/?ref=snap"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="U$1" library="TP4056" deviceset="TP4056" device=""/>
<part name="J1" library="B2B-XH-A" deviceset="B2B-XH-A" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="U$1" gate="G$1" x="31.75" y="48.26" smashed="yes"/>
<instance part="J1" gate="G$1" x="69.85" y="46.99" smashed="yes">
<attribute name="NAME" x="67.31" y="53.34" size="1.778" layer="95"/>
<attribute name="VALUE" x="67.31" y="41.91" size="1.778" layer="96"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="B+"/>
<pinref part="J1" gate="G$1" pin="1"/>
<wire x1="52.07" y1="50.8" x2="52.07" y2="52.07" width="0.1524" layer="91"/>
<wire x1="52.07" y1="52.07" x2="62.23" y2="49.53" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U$1" gate="G$1" pin="B-"/>
<pinref part="J1" gate="G$1" pin="2"/>
<wire x1="52.07" y1="45.72" x2="52.07" y2="49.53" width="0.1524" layer="91"/>
<wire x1="52.07" y1="49.53" x2="62.23" y2="46.99" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
