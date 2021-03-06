/* (c) 2001-2003 by Marcin Wiacek */

#include <string.h>

#include <gammu-info.h>

#include "gsmnet.h"
#include "../misc/coding/coding.h"

const char *GSM_Countries[] = {

	"202", "Greece",
	"204", "Netherlands",
	"206", "Belgium",
	"208", "France",
	"213", "Andorra",
	"214", "Spain",
	"216", "Hungary",
	"218", "Bosnia Herzegovina",
	"219", "Croatia",
	"220", "Serbia and Montenegro",
	"222", "Italy",
	"226", "Romania",
	"228", "Switzerland",
	"230", "Czech Republic",
	"231", "Slovak Republic",
	"232", "Austria",
	"234", "Guernsey",
	"234", "Isle of Man",
	"234", "Jersey",
	"234", "United Kingdom",
	"238", "Denmark",
	"240", "Sweden",
	"242", "Norway",
	"244", "Finland",
	"246", "Lithuania",
	"247", "Latvia",
	"248", "Estonia",
	"250", "Russia",
	"255", "Ukraine",
	"257", "Belarus",
	"259", "Moldova",
	"260", "Poland",
	"262", "Germany",
	"266", "Gibraltar",
	"268", "Portugal",
	"270", "Luxembourg",
	"272", "Ireland",
	"274", "Iceland",
	"276", "Albania",
	"278", "Malta",
	"280", "Cyprus",
	"282", "Georgia",
	"283", "Armenia",
	"283", "Nagorno Karabakh Region",
	"284", "Bulgaria",
	"286", "Turkey",
	"288", "Faroe Islands",
	"290", "Greenland",
	"293", "Slovenia",
	"294", "Macedonia",
	"295", "Liechtenstein",

	"302", "Canada",
	"310", "U.S.A.",
	"311", "U.S.A.",
	"334", "Mexico",
	"338", "Jamaica",
	"340", "French West Indies",
	"342", "Barbados",
	"344", "Antigua & Barbuda",
	"346", "Cayman Islands",
	"350", "Bermuda",
	"352", "Grenada",
	"362", "Netherlands Antilles",
	"363", "Aruba",
	"364", "Bahamas",
	"368", "Cuba",
	"370", "Dominican Republic",
	"374", "Trinidad and Tobago",

	"400", "Azerbaijan",
	"401", "Kazakhstan",
	"402", "Bhutan",
	"404", "India",
	"410", "Pakistan",
	"412", "Afghanistan",
	"413", "Sri Lanka",
	"414", "Myanmar",
	"415", "Lebanon",
	"416", "Jordan",
	"417", "Syria",
	"418", "Iraq",
	"419", "Kuwait",
	"420", "Saudi Arabia",
	"421", "Yemen",
	"422", "Oman",
	"424", "United Arab Emirates",
	"425", "Israel",
	"425", "Palestinian Authority",
	"426", "Bahrain",
	"427", "Qatar",
	"428", "Mongolia",
	"429", "Nepal",
	"432", "Iran",
	"434", "Uzbekistan",
	"436", "Tajikistan",
	"437", "Kyrgyz Republic",
	"438", "Turkmenistan",
	"440", "Japan",
	"450", "South Korea",
	"452", "Vietnam",
	"454", "Hong Kong",
	"455", "Macau",
	"456", "Cambodia",
	"457", "Lao",
	"460", "China",
	"466", "Taiwan",
	"467", "North Korea",
	"470", "Bangladesh",
	"472", "Maldives",

	"502", "Malaysia",
 	"505", "Australia",
	"510", "Indonesia",
	"514", "East Timor",
	"515", "Philippines",
	"520", "Thailand",
	"525", "Singapore",
	"528", "Brunei Darussalam",
	"530", "New Zealand",
	"537", "Papua New Guinea",
	"539", "Tonga",
	"541", "Vanuatu",
	"542", "Fiji",
	"545", "Kiribati",
	"546", "New Caledonia",
	"547", "French Polynesia",
	"550", "Micronesia",

	"602", "Egypt",
	"603", "Algeria",
	"604", "Morocco",
	"605", "Tunisia",
	"607", "Gambia",
	"608", "Senegal",
	"609", "Mauritania",
	"610", "Mali",
	"611", "Guinea",
	"612", "Cote d'Ivoire",
	"613", "Burkina Faso",
	"614", "Niger",
	"615", "Togo",
	"616", "Benin",
	"617", "Mauritius",
	"618", "Liberia",
	"619", "Sierra Leone",
	"620", "Ghana",
	"621", "Nigeria",
	"622", "Chad",
	"624", "Cameroon",
	"625", "Cape Verde",
	"626", "Sao Tome and Principe",
	"627", "Equatorial Guinea",
	"628", "Gabon",
	"629", "Congo",
	"630", "Congo",
	"631", "Angola",
	"633", "Seychelles",
	"634", "Mozambique",
	"634", "Sudan",
	"635", "Rwanda",
	"636", "Ethiopia",
	"637", "Somalia",
	"638", "Djibouti",
	"639", "Kenya",
	"640", "Tanzania",
	"641", "Uganda",
	"642", "Burundi",
	"643", "Mozambique",
	"645", "Zambia",
	"646", "Madagascar",
	"647", "Reunion",
 	"648", "Zimbabwe",
	"649", "Namibia",
	"650", "Malawi",
	"651", "Lesotho",
	"652", "Botswana",
	"653", "Swaziland",
	"654", "Comoros",
	"655", "South Africa",

	"702", "Belize",
	"706", "El Salvador",
	"710", "Nicaragua",
	"712", "Costa Rica",
	"714", "Panama",
	"716", "Peru",
	"722", "Argentina",
	"724", "Brazil",
	"730", "Chile",
	"732", "Colombia",
	"734", "Venezuela",
	"736", "Bolivia",
	"740", "Ecuador",
	"744", "Paraguay",
	"746", "Suriname",

	"999", "Dummy",

	NULL
};

const char *GSM_Networks[] = {

	"202 01", "Cosmote",
	"202 05", "PANAFON",
	"202 09", "Q-TELECOM",
	"202 10", "TELESTET",
	"204 04", "Vodafone NL",
	"204 08", "KPN Telecom",
	"204 12", "O2",
	"204 16", "BEN",
	"204 20", "Dutchtone NV",
	"206 01", "PROXIMUS",
	"206 10", "Mobistar",
	"206 20", "Base",
	"208 01", "ITINERIS",
	"208 10", "SFR",
	"208 20", "Bouygues Telecom",
	"213 03", "MOBILAND",
	"214 01", "Airtel GSM 900-Spain",
	"214 03", "Retevision Movil",
	"214 04", "Xfera",
	"214 07", "MOVISTAR",
	"216 01", "Pannon GSM",
	"216 30", "T-Mobile H",
	"216 70", "Vodafone HU",
	"218 03", "ERONET",
	"210 01", "Cronet",
	"218 05", "Mobilna Srpske",
	"218 90", "GSMBIH",
	"219 01", "CRONET",
	"219 10", "VIP",
	"220 01", "MOBTEL",
	"220 02", "ProMonte GSM",
	"220 03", "Telekom Srbije",
	"220 04", "MONET",
	"220 07", "Promonte",
	"222 01", "Telecom Italia Mobile",
	"222 10", "OMNITEL",
	"222 88", "Wind Telecomunicazioni SpA",
	"222 98", "Blu s.p.a. Telefonia",
	"222 99", "H3G",
	"226 01", "CONNEX GSM",
	"226 03", "Cosmorom S.A.",
	"226 10", "DIALOG",
	"228 01", "NATEL International",
	"228 02", "diAx Mobile AG",
	"228 03", "ORANGE",
	"228 08", "Tele2",
	"230 01", "T-Mobile CZ",
	"230 02", "O2 CZ",
	"230 03", "Vodafone CZ",
	"231 01", "Orange SK",
	"231 02", "T-Mobile SK",
	"231 06", "O2 SK",
	"232 01", "A1",
	"232 03", "T-Mobile AT",
	"232 05", "ONE",
	"232 07", "tele.ring",
	"232 10", "3 AT",
	"234 10", "Cellnet",
	"234 15", "Vodafone UK",
	"234 20", "3 UK",
	"234 30", "T-Mobile UK",
	"234 33", "ORANGE",
	"234 50", "Jersey Telecoms GSM",
	"234 55", "Guernsey Telecoms GSM",
	"234 58", "PRONTO GSM",
	"234 90", "Jersey",
	"238 01", "TDK-MOBIL",
	"238 02", "SONOFON",
	"238 20", "TELIA DK",
	"238 30", "Mobilix",
	"240 01", "Telia AB",
	"240 02", "3",
	"240 07", "COMVIQ",
	"240 08", "EUROPOLITAN",
	"242 01", "Telenor Mobil",
	"242 02", "NetCom GSM",
	"244 03", "Telia City (Finland)",
	"244 05", "Radiolinja",
	"244 09", "Finnet",
	"244 12", "DNA (FI2G)",
	"244 14", "Alands Mobiltelefon",
	"244 91", "Sonera",
	"246 01", "OMNITEL",
	"246 02", "Bite GSM",
	"246 03", "TELE2",
	"246 04", "TELE2",
	"247 01", "LMT LV",
	"247 02", "LV Tele2",
	"247 05", "LV Bite",
	"248 01", "EMT GSM",
	"248 02", "Radiolinja Eesti AS",
	"248 03", "Q GSM",
	"250 01", "Mobile Telesystems",
	"250 02", "North-West GSM",
	"250 03", "NCC",
	"250 04", "SIBCHALLENGE LTD",
	"250 05", "Siberian Cellular Systems 900",
	"250 07", "BM Telecom",
	"250 10", "Don Telecom",
	"250 11", "Orensot",
	"250 12", "FECS-900",
	"250 13", "Kuban GSM",
	"250 15", "SMARTS-Ufa",
	"250 16", "NTC",
	"250 17", "Ermak RMS",
	"250 19", "BASHCELL",
	"250 20", "Cellular Communcations of Udmurtia",
	"250 28", "Extel",
	"250 39", "Uraltel",
	"250 44", "North Caucasian GSM",
	"250 92", "Primtelefone",
	"250 99", "BeeLine",
	"255 01", "UMC",
	"255 02", "WellCOM",
	"255 03", "Kyivstar",
	"255 05", "Golden Telecom",
	"255 06", "life:)",
	"257 01", "VELCOM",
	"257 02", "MTS",
	"259 01", "VOXTEL",
	"259 02", "Moldcell",
	"260 01", "PLUS GSM",
	"260 02", "ERA GSM",
	"260 03", "Orange PL",
	"262 01", "T-Mobile D",
	"262 02", "D2 PRIVAT",
	"262 03", "E-Plus",
	"262 07", "Interkom",
	"262 13", "Mobilcom Multimedia GMBH",
	"266 01", "Gibtel GSM",
	"268 01", "TELECEL",
	"268 03", "OPTIMUS",
	"268 06", "TMN",
	"270 01", "LUXGSM",
	"270 77", "TANGO",
	"272 01", "EIRCELL-GSM",
	"272 02", "Digifone",
	"272 03", "METEOR",
	"274 01", "Landssiminn GSM 900",
	"274 02", "TAL hf",
	"274 03", "Islandssimi GSM ehf",
	"274 04", "Viking Wireless",
	"276 01", "AMC",
	"276 02", "vodafone",
	"278 01", "Vodafone Malta Limited",
	"278 21", "go mobile",
	"280 01", "CYTAGSM",
	"282 01", "Geocell Limited",
	"282 02", "Magti GSM",
	"283 01", "ArmGSM",
	"283 04", "NKRGSM",
	"284 01", "M-TEL GSM BG",
	"284 05", "GLOBUL",
	"286 01", "Turkcell",
	"286 02", "TELSIM GSM",
	"286 03", "ARIA",
	"286 04", "AYCELL",
	"288 01", "Faroese Telecom",
	"288 02", "KALL-GSM",
	"290 01", "Tele Greenland",
	"293 40", "SI.MOBIL d. d.",
	"293 41", "MOBITEL",
	"293 70", "SI VEGA 070",
	"294 01", "MobiMak",
	"294 02", "MTS A.D",
	"295 01", "Telecom FL AG",
	"295 02", "Orange FL",
	"295 05", "FL1",
	"295 77", "Tele 2 AG",

	"302 37", "Microcell Connexions Inc",
	"302 72", "Rogers AT&T",
	"310 00", "Mid-Tex Cellular",
	"310 01", "Cellnet",
	"310 02", "Sprint Spectrum",
	"310 03", "Centennial Communications",
	"310 04", "Concho Cellular Telephone Co.",
	"310 07", "Highland",
	"310 08", "Corr Wireless Communications",
	"310 10", "Plateau Wireless",
	"310 11", "Wireless 2000 Telephone Co.",
	"310 15", "BellSouth Mobility DCS",
	"310 16", "T-Mobile",
	"310 17", "Pac Bell",
	"310 19", "Dutch Harbor",
	"310 20", "T-Mobile",
	"310 21", "T-Mobile",
	"310 22", "T-Mobile",
	"310 23", "T-Mobile",
	"310 24", "T-Mobile",
	"310 25", "T-Mobile",
	"310 26", "T-Mobile",
	"310 27", "T-Mobile",
	"310 31", "T-Mobile",
	"310 32", "Smith Bagley",
	"310 34", "Westlink Communications",
	"310 38", "AT&T Wireless",
	"310 45", "North East Colorado Cellular",
	"310 46", "TMP Corp",
	"310 50", "PSC Wireless",
	"310 53", "West Virginia Wireless",
	"310 56", "Dobson",
	"310 58", "T-Mobile",
	"310 59", "Cellular One",
	"310 63", "Choice Wireless L.C.",
	"310 64", "Airadigm Communications",
	"310 66", "T-Mobile",
	"310 68", "NPI Wireless",
	"310 69", "Immix Wireless",
	"310 74", "TELEMETRIX",
	"310 77", "Iowa Wireless Services LP",
	"310 79", "PinPoint Wireless",
	"310 80", "T-Mobile",
	"310 94", "Poka Lambro Telcomm. Ltd. d/b/a Digital Cellular",
	"311 11", "High Plains Wireless, L.P",
	"334 02", "TELCEL GSM",
	"334 03", "MOVISTAR GSM",
	"338 05", "Digicel",
	"338 18", "Cable and Wireless Jamaica Limited",
	"340 01", "AMERIS",
	"340 03", "Saint Martin et Saint Barthelemy Tel Cell SARL",
	"340 08", "AMIGO GSM",
	"340 20", "Bouygues Telecom Caraibe",
	"342 60", "Cable & Wireless (Barbados) Limited",
	"344 03", "APUA PCS",
	"346 14", "Cable & Wireless (Cayman Islands) Limited",
	"350 01", "Telecommunications (Bermuda & West Indies) Ltd",
	"350 02", "MOBILITY LTD.",
	"352 13", "Trans-World Telecom Caribbean (Grenada)",
	"362 51", "Telcell N.V.",
	"362 69", "CT GSM",
	"362 91", "UTS Wireless Curacao",
	"363 01", "SETAR GSM - GSM 1800",
	"364 39", "The Bahamas Telecommunications Company Ltd",
	"368 01", "C_Com",
	"370 01", "ORANGE",
	"374 12", "TSTT",

	"400 01", "AZERCELL GSM",
	"400 02", "Bakcell GSM 2000",
	"401 01", "K-MOBILE",
	"401 02", "K'CELL",
	"402 11", "B-Mobile",
	"404 01", "Aircel Digilink India Limited - Haryana",
	"404 02", "AirTel - Punjab",
	"404 03", "AirTel - Himachal Pradesh Circle",
	"404 04", "IDEA - Delhi Circle",
	"404 05", "HUTCH",
	"404 07", "TATA Cellular",
	"404 09", "Reliance Telecom Private Ltd",
	"404 10", "AirTel",
	"404 11", "Essar Cellphone",
	"404 12", "Escotel",
	"404 13", "HESL - Andhra Pradesh",
	"404 14", "Modicom",
	"404 15", "Essar Cellphone",
	"404 19", "Escotel Kerala",
	"404 20", "Max Touch",
	"404 21", "BPL - Mobile",
	"404 22", "IDEA - Maharashtra Circle",
	"404 24", "IDEA - Gujarat Circle",
	"404 27", "BPL USWEST Cellular",
	"404 30", "Command",
	"404 31", "AirTel - Kolkata",
	"404 34", "CellOne",
	"404 40", "SkyCell",
	"404 41", "RPG Cellular",
	"404 42", "AIRCEL",
	"404 43", "BPL Mobile - Tamil Nadu/Pondicherry",
	"404 44", "Spice - Karnataka",
	"404 45", "Airtel - Karnataka",
	"404 46", "BPL Mobile - Kerala",
	"404 49", "Airtel - Andhra Pradesh",
	"404 56", "Escotel UP(W)",
	"404 60", "Aircel Digilink India Limited - Rajasthan",
	"404 68", "Mahanagar Telephone Nigam Ltd - Delhi",
	"404 69", "Mahanagar Telephone Nigam Ltd - Mumbai",
	"404 70", "Oasis Cellular",
	"404 78", "IDEA - Madhya Pradesh",
	"404 84", "HESL - Chennai",
	"404 86", "HESL - Karnataka",
	"404 90", "AirTel - Maharashtra",
	"404 92", "AirTel - Mumbai Metro",
	"404 93", "AirTel - Madhya Pradesh",
	"404 94", "AirTel - Tamilnadu",
	"404 95", "AirTel - Kerala",
	"404 96", "AirTel - Haryana",
	"404 97", "AirTel - Uttar Pradesh (West)",
	"404 98", "AirTel - Gujarat",
	"410 01", "Mobilink",
	"410 03", "Ufone",
	"412 01", "AWCC",
	"412 20", "TDCA",
	"413 02", "DIALOG GSM",
	"413 03", "Celltel Infiniti",
	"413 07", "Mobitel (Pvt) Limited",
	"414 01", "MPT GSM Network",
	"415 01", "CELLIS",
	"415 03", "LIBANCELL",
	"416 01", "Fastlink",
	"416 77", "MOBILECOM",
	"417 01", "SYRIATEL",
	"417 02", "94",
	"417 09", "MOBILE SYRIA",
	"419 02", "MTCNet",
	"419 03", "Wataniya Telecom",
	"420 01", "Al Jawwal",
	"420 07", "E.A.E",
	"421 01", "Yemen Company for Mobile Telephony",
	"421 02", "Spacetel",
	"422 02", "GTO",
	"424 02", "UAE-ETISALAT",
	"425 01", "Partner Communications Company Ltd",
	"425 02", "Cellcom Israel Ltd",
	"425 05", "Palestine Telecommunications Co. P.L.C",
	"426 01", "BHR MOBILE PLUS",
	"426 02", "MTC VODAFONE Bahrain",
	"427 01", "QATARNET",
	"428 99", "MobiCom",
	"429 01", "Nepal Mobile",
	"432 11", "TCI",
	"432 14", "KFZO",
	"432 19", "MTCE",
	"434 02", "Uzmacom",
	"434 04", "Daewoo Unitel",
	"434 05", "Coscom",
	"434 07", "Uzdunrobita GSM",
	"436 01", "JSC Somoncom",
	"436 02", "Indigo Tajikistan",
	"436 03", "Mobile Lines of Tajikistan",
	"436 05", "Tajik Tel",
	"437 01", "Bitel",
	"438 01", "BCTI",
	"440 10", "NTT DoCoMo, Inc",
	"440 20", "SoftBank",
	"450 02", "KT ICOM",
	"452 01", "MOBIFONE",
	"452 02", "Vinaphone",
	"454 00", "TCSL GSM",
	"454 03", "3",
	"454 04", "HKGHT",
	"454 06", "SMARTONE GSM",
	"454 10", "New World PCS",
	"454 12", "PEOPLES",
	"454 16", "SUNDAY",
	"455 00", "SMC Macau",
	"455 01", "TELEMOVEL+ GSM900-Macau",
	"455 03", "Hutchison Telecom",
	"456 01", "MobiTel",
	"456 02", "SAMART-GSM",
	"456 18", "Cambodia Shinawatra",
	"457 01", "Lao Shinawatra Telecom",
	"457 02", "ETL Mobile",
	"457 03", "LAT MOBILE",
	"457 08", "Millicom Lao Co Ltd",
	"460 00", "China Telecom GSM",
	"460 01", "CU-GSM",
	"466 01", "Far EasTone Telecoms 900",
	"466 06", "TUNTEX GSM 1800",
	"466 88", "KG Telecom",
	"466 89", "T3G",
	"466 92", "Chunghwa GSM",
	"466 93", "MobiTai",
	"466 97", "TWNGSM",
	"466 99", "TransAsia",
	"467 19", "Sun Net",
	"470 01", "GrameenPhone Ltd",
	"470 02", "AKTEL",
	"470 03", "ShebaWorld",
	"470 19", "Mobile 2000",
	"472 01", "DhiMobile GSM 900",

	"502 12", "Maxis Mobile",
	"502 13", "TM Touch",
	"502 16", "DiGi 1800",
	"502 17", "ADAM",
	"502 19", "CELCOM",
	"505 01", "MobileNet",
	"505 02", "OPTUS",
	"505 03", "VODAFONE",
	"505 06", "Hutchison 3G Australia Pty Limited",
	"505 08", "One.Tel",
	"510 01", "SATELINDO",
	"510 08", "LIPPO TELECOM",
	"510 10", "TELKOMSEL",
	"510 11", "Excelcom",
	"510 21", "INDOSAT",
	"514 02", "Timor Telecom",
	"515 01", "ISLACOM",
	"515 02", "Globe Telecom",
	"515 03", "Smart Gold GSM",
	"515 05", "Digitel Mobile/Sun Cellular",
	"520 01", "AIS GSM",
	"520 10", "WCS",
	"520 15", "ACT Mobile",
	"520 18", "Worldphone 1800",
	"520 23", "HELLO",
	"520 99", "TA Orange Co",
	"525 01", "SingTel Mobile",
	"525 02", "ST-PCN",
	"525 03", "MOBILEONE",
	"525 05", "StarHub Pte Ltd",
	"528 11", "DSTCom",
	"530 01", "Vodafone New Zealand Limited",
	"537 01", "Bee Mobile",
	"539 01", "U-CALL",
	"539 43", "Shoreline Communications",
	"541 01", "SMILE",
	"542 01", "Vodafone",
	"545 09", "Kiribati Frigate",
	"546 01", "Mobilis",
	"547 20", "VINI",
	"550 01", "FSM Telecommunications Corporation",

	"602 01", "MobiNil",
	"602 02", "Tunicell",
	"603 01", "ALGERIAN MOBILE NETWORK",
	"603 02", "Djezzy",
	"604 00", "Meditel",
	"604 01", "I A M",
	"605 02", "TUNTEL",
	"605 03", "TUNISIANA",
	"607 01", "Gamcell",
	"607 02", "AFRICELL",
	"608 01", "ALIZE",
	"608 02", "Sentel GSM",
	"609 01", "MATTEL",
	"609 10", "MAURITEL",
	"610 01", "Malitel",
	"610 02", "IKATEL",
	"611 01", "Mobilis Guinee",
	"611 02", "Lagui",
	"612 01", "CORA de COMSTAR",
	"612 03", "IVOIRIS",
	"612 05", "Telecel",
	"613 02", "Celtel Burkina Faso",
	"613 03", "Telecel Faso SA",
	"614 02", "Celtel Niger",
	"614 03", "TELECEL Niger",
	"615 01", "TOGO CELL",
	"616 00", "Bell Benin Communication BBCOM",
	"616 01", "LIBERCOM",
	"616 02", "TELECEL BENIN",
	"616 03", "BeninCell",
	"617 01", "Cellplus Mobile Comms",
	"617 10", "EMTEL",
	"618 01", "Omega",
	"619 01", "Celtel (SL) Limited",
	"620 01", "SPACEFON",
	"620 02", "Ghana Telecom Mobile",
	"620 03", "MOBITEL",
	"621 20", "Econet Wireless Nigeria",
	"621 30", "MTN Nigeria",
	"621 40", "Mtel",
	"621 50", "Glo Mobile",
	"622 01", "CELTEL",
	"622 02", "Libertis",
	"624 01", "MTN Cameroon Ltd",
	"624 02", "Orange",
	"625 01", "CVMOVEL",
	"626 01", "CSTmovel",
	"627 01", "GETESA",
	"628 01", "LIBERTIS S.A.",
	"628 02", "Telecel Gabon SA",
	"628 03", "Celtel Gabon SA",
	"629 01", "CelTel Congo SA",
	"629 10", "Libertis Telecom",
	"630 01", "VODACOM CONGO",
	"630 02", "CelTel Congo SA",
	"630 04", "CELLCO",
	"630 89", "OASIS",
	"631 02", "UNITEL",
	"633 01", "Seychelles Cellular Services",
	"633 10", "AIRTEL",
	"634 01", "MobiTel",
	"635 10", "Rwandacell",
	"636 01", "ETMTN",
	"637 01", "TELESOM",
	"637 10", "Nationlink",
	"637 82", "Telsom Mobile",
	"638 01", "Evatis",
	"639 02", "Safaricom",
	"639 03", "KenCell",
	"640 01", "TRITEL",
	"640 02", "MOBITEL",
	"640 03", "ZANTEL",
	"640 04", "Vodacom Tanzania Ltd",
	"640 05", "Celtel Tanzania",
	"641 01", "CelTel Cellular",
	"641 10", "MTN-Uganda",
	"641 11", "mango",
	"642 01", "Spacetel - Burundi",
	"642 02", "ANTARIS",
	"643 01", "T.D.M GSM 900",
	"643 04", "Vodacom Mozambique",
	"645 01", "ZAMCELL",
	"645 02", "Telecel Zambia Limited",
	"646 01", "Madacom",
	"646 02", "ANTARIS",
	"646 03", "Sacel Madagascar S.A.",
	"647 00", "Orange Reunion",
	"647 02", "Outremer Telecom",
	"647 10", "SRR",
	"648 01", "NET*ONE",
	"648 03", "Telecel",
	"648 04", "Econet",
	"649 01", "MTC",
	"650 01", "Callpoint 900",
	"650 10", "CelTel Limited",
	"651 01", "Vodacom Lesotho (Pty) Ltd",
	"651 02", "Econet Ezi-Cel",
	"652 01", "MASCOM",
	"652 02", "ORANGE",
	"653 10", "Swazi MTN Limited",
	"654 00", "HURI",
	"655 01", "Vodacom",
	"655 07", "Cell C",
	"655 10", "MTN",
	"680 38", "NPI Wireless",

	"702 67", "Belize Telecommunications Ltd",
	"702 68", "International Telecommunication Limited (INTELCO)",
	"706 01", "CTE Telecom Personal SA de CV",
	"706 02", "Digicel",
	"710 21", "ENITEL",
	"710 73", "SERCOM S.A.",
	"712 01", "I.C.E.",
	"714 01", "Cable & Wireless Panama",
	"716 10", "TIM Peru",
	"722 07", "UNIFON",
	"722 31", "CTI Movil",
	"722 34", "Personal",
	"722 35", "PORT-HABLE",
	"724 03", "TIM BRASIL",
	"724 04", "TIM BRASIL",
	"724 05", "Claro Celular",
	"724 16", "Brasil Telecom",
	"724 31", "TNL PCS S.A.",
	"730 01", "Entel Telefonia Movi",
	"730 02", "TELEFONICA",
	"730 10", "Entel PCS",
	"732 10", "Colombia Movil SA",
	"734 01", "Infonet",
	"734 02", "DIGITEL",
	"734 03", "DIGICEL C.A.",
	"736 01", "Nuevatel PCS De Bolivia SA",
	"736 02", "Entel SA",
	"740 01", "Conecel S.A. (Consorcio Ecuatoriano de Telecomunicaciones S.A.)",
	"744 01", "VOX",
	"744 02", "Hutchison Telecommunications Paraguay S.A",
	"744 04", "Telecel Paraguay",
	"746 02", "TELESUR.GSM",

	"999 99", "GammuTel",

	NULL
};

const unsigned char *GSM_GetNetworkName(const char *NetworkCode)
{
	int		i = 0;
	static char	retval[200];
	char		NetworkCodeFull[7] = "      ";

	EncodeUnicode(retval, "unknown", 7);
	if ((strlen(NetworkCode) == 5) ||
			(strlen(NetworkCode) == 6)) {
		strncpy(NetworkCodeFull, NetworkCode, 3);
		strncpy(NetworkCodeFull + 4, NetworkCode + strlen(NetworkCode) - 2, 2);
		while (GSM_Networks[i * 2] != NULL) {
			if (strncmp(GSM_Networks[i * 2], NetworkCodeFull, 6) == 0) {
				EncodeUnicode(retval,
						GSM_Networks[i * 2 + 1],
						strlen(GSM_Networks[i * 2 + 1]));
				break;
			}
			i++;
		}
	}
	return retval;
}

const unsigned char *GSM_GetCountryName(const char *CountryCode)
{
	int		i = 0;
	static char	retval[200];

	EncodeUnicode(retval,"unknown",7);
	while (GSM_Countries[i*2] != NULL) {
		if (!strncmp(GSM_Countries[i*2],CountryCode,3)) {
			EncodeUnicode(retval, GSM_Countries[i*2+1], strlen(GSM_Countries[i*2+1]));
			break;
		}
		i++;
	}
	return retval;
}

void NOKIA_EncodeNetworkCode(unsigned char* buffer, const char* input)
{
	EncodeBCD(buffer, input, 6, FALSE);
	buffer[1] = buffer[1] | 0xf0;
}

void NOKIA_DecodeNetworkCode(const unsigned char* buffer, char* output)
{
	DecodeBCD(output, buffer, 3);
	output[6] = output[5];
	output[5] = output[4];
	output[4] = output[3];
	output[3] = ' ';
}

/* How should editor hadle tabs in this file? Add editor commands here.
 * vim: noexpandtab sw=8 ts=8 sts=8:
 */
