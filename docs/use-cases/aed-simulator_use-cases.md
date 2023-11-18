## Use Case 0 - Using the AED
<u>Primary Actor</u>: Device user
<u>Precondition</u>: User has the device and a victim is in need of treatment (victim is unconscious, not breathing, doesn't show a pulse). User has received at least basic training in life support.
<u>Success Guarantee</u>: The user is able to successfully treat the victim using the device.
<u>Main Success Scenario</u>: 
1. User performs set-up and check out procedure (UC1).
2. User presses ON/OFF button to boot up the device.
3. Device performs self test (UC2).
4. Device notifies user to stay calm.
5. Device Responsiveness Indicator flashes and device notifies user to check victim's responsiveness.
6. User checks victim responsiveness.
7. Device Help Indicator flashes and device instructs user to call for help.
8. User calls or sends somebody for help.
9. User affixes PASS (Passive Airway Support System) under victim's shoulders.
10. Device Attach Electrodes Indicator flashes and device instructs user to attach defib pads.
11. User attaches electrodes to victim (UC3).
12. Device Analysis Indicator flashes and user is warned to stand clear and leave victim untouched.
13. User stands by, ensuring victim is still and untouched.
14. Device notifies user it is analyzing victim's heart rhythm to detect ventricular fibrillation or ventricular tachycardia.
15. Device detects ventricular fibrillation or ventricular tachycardia.
16. Device Shock Indicator flashes and device notifies user a shock will be delivered shortly.
17. Device emits shock tone and shock is delivered to victim.
18. Device CPR Indicator flashes and notifies user to start CPR.
19. After 2 minutes of CPR have elapsed, device Analyzing Indicator flashes and device notifies user to stop CPR.
20. Repeat from step 11 as necessary.
<u>Postcondition</u>: The victim has been treated successfully.
<u>Extensions</u>:
\*a. Device shows red "X" in Status Indicator window or device beeps while OFF.
	\*a1. User checks that cable is correctly attached.
	\*a2. If device is still inoperable, user removes AED from service. 
\*b. Device shows red "X" in Status Indicator window when device is ON.
	\*b1. User turns the device OFF and then ON again.
	\*b2.  If device is still inoperable, user removes AED from service. 
\*c. Device communicates "Change batteries" prompt.
	\*c1. User replaces all batteries.
\*d. Device emits "Plug in cable" prompt
	\*d1. User checks cable connection between device and electrodes.
4a. Device has audio recording option installed and configured.
	4a1. Device begins audio recording.
3a. Device fails self test.
	3a1. User attempts to repair device by replacing batteries or electrodes.
	3a2. If self test fails again, AED is removed from service and ZOLL technical service is called.
6a. Victim is unconscious.
	6a1. User refrains from using device.
6b. Victim is breathing.
	6b1. User refrains from using device.
6c. Victim has a detectable pulse or other sign of circulation.
	6c1. User refrains from using device.
9a. Victim has head or neck trauma.
	9a1. User does not affix the PASS.
10a. Device has audio recording option installed and configured.
	10a1. Device clears old audio data after 10 seconds.
13a. Device notifies user "Analysis is halted. Keep victim still".
	13a1. User ensures victim is kept still.
	13b1. User in moving vehicle ensures vehicle is halted before performing analysis.
14a. Device does not detect ventricular fibrillation or ventricular tachycardia.
	14a1. Device CPR Indicator flashes and notifies user to start CPR.
	14a2. After 2 minutes of CPR have elapsed, device Analyzing Indicator flashes and device notifies user to stop CPR.
## Use Case 1 (UC1) - User Performs Set-up and Check out Procedure
<u>Primary Actor</u>: Device user
<u>Precondition</u>: User has device.
<u>Success Guarantee</u>: Device is in operable state.
<u>Main Success Scenario</u>: 
1. User inspects all external device surfaces for damage or missing parts.
2. User verifies new CPR-D-padz and Pedi-padz II are included in device and within their expiration date.
3. User removes any old batteries.
4. User inserts 10 new batteries into device.
5. User presses button in battery well.
6. User inspects electrode connector for damage or missing pins, then connects electrode cable and packs electrodes into device cover, closing cover when completed.
7. User turns device on.
8. Device communicates "Unit OK" message to user, as well as "Adult Pads" or "Pediatric Pads" message.
9. User turns device off.
10. User waits 2 minutes and verifies green check status in indicator window, and that device does not emit beeping tone.
11. User places device into service.
12. User once again checks to verify green check status in indicator window.
<u>Postcondition</u>: The device has been set up and approved for use.
<u>Extensions</u>: 
10a. Device emits beeping tone or shows red "X" in Status Indicator window.
	10a1. User checks that cable is correctly attached.
	10a2. If device is still inoperable, user removes AED from service. 
12a. Device shows red "X" in Status Indicator window.
	12a1. User checks that cable is correctly attached.
	12a2. If device is still inoperable, user removes AED from service. 
## Use Case 2 (UC2) - AED Self Test
<u>Primary Actor</u>: AED device
<u>Precondition</u>: Device has been powered on or ON/OFF button has been held for more than 5 seconds.
<u>Success Guarantee</u>: All steps pass self-inspection.
<u>Main Success Scenario</u>: 
1. Device verifies adequate battery capacity shown by battery usage indicator.
2. Device verifies defibrillation electrodes are properly connected.
3. Device verifies ECG signal acquisition is functional.
4. Device verifies operation of defibrillator electronics can charge and discharge at 2 joules.
5. Device verifies hardware and software integrity.
6. Device verifies operation of CPR circuitry and sensor.
7. Device verifies audio functionality.
<u>Postcondition</u>: The device has been approved for safe use.
<u>Extensions</u>: 
1a. Device does not have adequate battery capacity.
	1a1. Device self test fails and unit emits "Unit failed" voice message.
2a. Defibrillation electrodes are not properly connected.
	2a1. Device self test fails and unit emits "Unit failed" voice message.
3a. ECG signal acquisition has malfunctioned.
	3a1. Device self test fails and unit emits "Unit failed" voice message.
4a. Defibrillator electronics are not working correctly.
	4a1. Device self test fails and unit emits "Unit failed" voice message.
5a. Hardware or software is damaged.
	5a1. Device self test fails and unit emits "Unit failed" voice message.
6a. CPR circuitry or sensor are not operating correctly.
	6a1. Device self test fails and unit emits "Unit failed" voice message.
7a. Audio functionality is not working.
	7a1. Device self test fails and unit emits "Unit failed" voice message.
## Use Case 3 (UC3) - Applying Electrodes to Victim
<u>Primary Actor</u>: Device user
<u>Precondition</u>: The device is powered on and has passed the self test.
<u>Success Guarantee</u>: Electrodes have been successfully applied to victim's chest.
<u>Main Success Scenario</u>: 
1. User removes clothing covering the victim's chest.
2. User ensures victim's chest is dry.
3. User clips or shaves excessive hair on victim's chest.
4. User unpacks and unfolds CPR-D-padz electrodes, placing them on victim according to package.
5. User places sensor on middle of victim's breastbone, between the nipples.
6. User presses CPR sensor with right hand from center out to adhere electrode to skin, pulling number 2 tab to peel back protective backing.
7. User presses CPR sensor with left hand from center out to adhere electrode to skin, pulling number 3 tab to peel back protective backing.
<u>Postcondition</u>: The victim is ready for treatment.
<u>Extensions</u>:
4a. User determines victim is a child.
	4a1. User unpacks and unfolds Pedi-padz II electrodes, placing them on victim according to package.
	4a2. User removes round electrode from backing material and places it on victim's chest.
	4a3. User places hand on electrode edge, using other hand to roll electrode onto victim's chest and push out any air underneath it.
	4a4. User rolls victim onto their chest and removes square node from package, placing it on victim's back.
	4a5. User places hand on electrode edge, using other hand to roll electrode onto victim's chest and push out any air underneath it.
	4a6. User rolls victim onto their back and follows device's prompts.
7a. Victim is large or there is a need to place electrode under breast.
	7a1. User tears lower pad at perforated line and extends it
	7a2. User places the pad slightly to the victim's left and below their left breast.
7b. Victim has an implanted pacemaker or defibrillator in the upper right chest.
	7b1. User angles electrodes to avoid placing them over the device.
	7b2. User ensures CPR sensor maintains position over lower half of breastbone.
