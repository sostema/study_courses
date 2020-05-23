package module6;

import processing.core.PApplet;
import processing.core.PGraphics;
import de.fhpotsdam.unfolding.UnfoldingMap;
import de.fhpotsdam.unfolding.utils.MapUtils;
import parsing.ParseFeed;
import de.fhpotsdam.unfolding.providers.*;
import de.fhpotsdam.unfolding.providers.Google.*;

import java.util.List;
import de.fhpotsdam.unfolding.data.Feature;
import de.fhpotsdam.unfolding.data.GeoJSONReader;
import java.util.HashMap;

import de.fhpotsdam.unfolding.marker.Marker;

// Visualizes Political Stability Rankings in different countries based on data from the world bank.
// Loads country shapes from a GeoJSON file via datareader.

public class PoliticalStability extends PApplet {
	UnfoldingMap map;
	HashMap<String, HashMap<String, Float>> countryDataMap;
	List<Feature> countries;
	List<Marker> countryMarkers;
	public String countryNameKey = "";
	public String countryPolKey = "";
	public String countryCorKey = "";
	public String countryGovKey = "";
	public String countryRegKey = "";
	public String countryRuleKey = "";
	public String countryVoiceKey = "";

	// You can ignore this.  It's to get rid of eclipse warnings
	private static final long serialVersionUID = 1L;

	// IF YOU ARE WORKING OFFILINE, change the value of this variable to true
	private static final boolean offline = true;
		
	/** This is where to find the local tiles, for working without an Internet connection */
	public static String mbTilesString = "blankLight-1-3.mbtiles";
	
	public void setup(){		
		size(900, 700, OPENGL);
		if (offline) {
		    map = new UnfoldingMap(this, 200, 50, 650, 600, new MBTilesMapProvider(mbTilesString));
		    
		}
		else {
			map = new UnfoldingMap(this, 200, 50, 650, 600, new Google.GoogleMapProvider());
			
		}
		
		MapUtils.createDefaultEventDispatcher(this, map);
		
		// load political data
		countryDataMap = ParseFeed.loadPoliticalStabilityFromCSV(this, "WGI_Data.csv");
		
		// load countries
		countries = GeoJSONReader.loadData(this, "countries.geo.json");
		countryMarkers = MapUtils.createSimpleMarkers(countries);
		map.addMarkers(countryMarkers);
		
		
		// load features into country markers
		for (Marker marker : countryMarkers){
			// find data for country of the current marker
			String countryId = marker.getId();
						
			if(countryDataMap.containsKey(countryId)){
				marker.setProperty("political stability", countryDataMap.get(countryId).get("Political Stability and Absence of Violence/Terrorism: Percentile Rank"));
				marker.setProperty("control of corruption", countryDataMap.get(countryId).get("Control of Corruption: Percentile Rank"));
				marker.setProperty("government effectiveness", countryDataMap.get(countryId).get("Government Effectiveness: Percentile Rank"));
				marker.setProperty("regulatory quality", countryDataMap.get(countryId).get("Regulatory Quality: Percentile Rank"));
				marker.setProperty("rule of law", countryDataMap.get(countryId).get("Rule of Law: Percentile Rank"));
				marker.setProperty("voice and accountability", countryDataMap.get(countryId).get("Voice and Accountability: Percentile Rank"));											
			}
		}
				
		// shade countries on political stability spectrum
		shadeCountries();

	}
	
	public void draw(){
		map.draw();
		addKey();
		
	}

	public void mouseClicked(){
		checkCountriesForClick(g, mouseX, mouseY);
	}
	// method for shading countries based on political stability.
	// blue indicates relative stability
	// red indicates relative instability
	private void shadeCountries(){
		//int colorLevel = (int) map(politicalStability, 40, 90, 10, 255);
		//marker.setColor(color(255-colorLevel, 100, colorLevel));
		for (Marker marker : countryMarkers){
			// find data for country of the current marker
			String countryId = marker.getId();			
			if(countryDataMap.containsKey(countryId)){					
				float politicalStability = (float) marker.getProperty("political stability");
				//System.out.println(politicalStability);
				int colorLevel = (int) map(politicalStability, 40, 100, 10, 255);
				marker.setColor(color(255-colorLevel, 100, colorLevel));					
			}
			else {
				marker.setColor(color(150,150,150));
			}
		}
	}
	
	private void checkCountriesForClick(PGraphics pg, float x, float y)
	{

		for (Marker marker : countryMarkers) {
			if (marker.isInside(map, mouseX, mouseY)) {
				// Hide all the other earthquakes and hide
				HashMap countryProps = marker.getProperties();
		    	String countryName = countryProps.get("name").toString();
		    	String countryPolStab = countryProps.get("political stability").toString();
		    	String countryControlOfCorruption = countryProps.get("control of corruption").toString();
		    	String countryGovEffectiveness = countryProps.get("government effectiveness").toString();
		    	String countryRegQuality = countryProps.get("regulatory quality").toString();
		    	String countryRuleLaw = countryProps.get("rule of law").toString();
		    	String countryVoice = countryProps.get("voice and accountability").toString();
		    	countryNameKey = countryName;
		    	countryPolKey = countryPolStab;
		    	countryCorKey = countryControlOfCorruption;
		    	countryGovKey = countryGovEffectiveness;
		    	countryRegKey = countryRegQuality;
		    	countryRuleKey = countryRuleLaw;
		    	countryVoiceKey = countryVoice;    	
			}
		}		
	}
	
	// helper method to draw key in GUI
		private void addKey() {	
			// Remember you can use Processing's graphics methods here
			fill(255, 250, 240);
			
			int xbase = 10;
			int ybase = 50;
			
			rect(xbase, ybase, 170, 300);
			
			fill(0);
			textAlign(LEFT, CENTER);
			textSize(10);
			text("Country Key", xbase+50, ybase+25);			
			text("Name: " + countryNameKey, xbase+5, ybase+50);
			text("Political Stability: " + countryPolKey, xbase+5, ybase+70);
			text("Control of Corruption: " + countryCorKey, xbase+5, ybase+90);
			text("Goverment Effectiveness: " + countryGovKey, xbase+5, ybase+110);
			text("Regulatory Quality: " + countryRegKey, xbase+5, ybase+130);
			text("Rule of Law: " + countryRuleKey, xbase+5, ybase+150);
			text("Voice and Accountability: " + countryVoiceKey, xbase+5, ybase+170);
			textSize(10);
			text("World Bank Dataset", xbase+60, ybase+270);
					
		}
	
}
