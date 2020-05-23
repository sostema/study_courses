package module3;

//Java utilities libraries
import java.util.ArrayList;
//import java.util.Collections;
//import java.util.Comparator;
import java.util.List;

//Processing library
import processing.core.PApplet;

//Unfolding libraries
import de.fhpotsdam.unfolding.UnfoldingMap;
import de.fhpotsdam.unfolding.marker.Marker;
import de.fhpotsdam.unfolding.data.Feature;
import de.fhpotsdam.unfolding.data.PointFeature;
import de.fhpotsdam.unfolding.geo.Location;
import de.fhpotsdam.unfolding.marker.SimplePointMarker;
import de.fhpotsdam.unfolding.providers.Google;
import de.fhpotsdam.unfolding.providers.MBTilesMapProvider;
import de.fhpotsdam.unfolding.utils.MapUtils;

//Parsing library
import parsing.ParseFeed;

/** EarthquakeCityMap
 * An application with an interactive map displaying earthquake data.
 * Author: UC San Diego Intermediate Software Development MOOC team
 * @author David Quisenberry
 * Date: October 7th, 2016
 * */
public class EarthquakeCityMap extends PApplet {

	// You can ignore this.  It's to keep eclipse from generating a warning.
	private static final long serialVersionUID = 1L;

	// IF YOU ARE WORKING OFFLINE, change the value of this variable to true
	private static final boolean offline = true;
	
	// Less than this threshold is a light earthquake
	public static final float THRESHOLD_MODERATE = 5;
	// Less than this threshold is a minor earthquake
	public static final float THRESHOLD_LIGHT = 4;

	/** This is where to find the local tiles, for working without an Internet connection */
	public static String mbTilesString = "blankLight-1-3.mbtiles";
	
	// The map
	private UnfoldingMap map;
	
	//feed with magnitude 2.5+ Earthquakes
	private String earthquakesURL = "http://earthquake.usgs.gov/earthquakes/feed/v1.0/summary/2.5_week.atom";

	
	public void setup() {
		size(950, 600, OPENGL);
		

		if (offline) {
		    map = new UnfoldingMap(this, 200, 50, 700, 500, new MBTilesMapProvider(mbTilesString));
		    earthquakesURL = "2.5_week.atom"; 	// Same feed, saved Aug 7, 2015, for working offline
		}
		else {
			map = new UnfoldingMap(this, 200, 50, 700, 500, new Google.GoogleMapProvider());
			// IF YOU WANT TO TEST WITH A LOCAL FILE, uncomment the next line
			earthquakesURL = "2.5_week.atom";
		}
		
	    map.zoomToLevel(2);
	    MapUtils.createDefaultEventDispatcher(this, map);	

	    List<Marker> markers = new ArrayList<Marker>(); 
	    //set colors
	    int yellow = color(255, 255, 0);
	    int blue = color(8, 31, 145);
	    int red = color(221, 30, 8);

	    //Use provided parser to collect properties for each earthquake
	    //PointFeatures have a getLocation method
	    List<PointFeature> earthquakes = ParseFeed.parseEarthquake(this, earthquakesURL);
	    
	    // These print statements show you (1) all of the relevant properties 
	    // in the features, and (2) how to get one property and use it
	    if (earthquakes.size() > 0) {
	    	PointFeature f = earthquakes.get(0);
	    	System.out.println(f.getProperties());
	    	Object magObj = f.getProperty("magnitude");
	    	float mag = Float.parseFloat(magObj.toString());
	    	// PointFeatures also have a getLocation method
	    }
	    
	    for(PointFeature eq: earthquakes){
	    	// creates the Simple Marker Object
	    	SimplePointMarker eqmarker = createMarker(eq);
	    	// get magnitude from Point Feature eq and convert it to float
	    	Object magObj = eq.getProperty("magnitude");
	    	float mag = Float.parseFloat(magObj.toString());		
	    	// set color of markers based on magnitude and set size of radius
	    	if (mag >= 5.0f){
	    		eqmarker.setColor(red);
	    		eqmarker.setRadius(10);
	    	}
	    	else if (mag >= 4.0f && mag < 5.0f ){
	    		eqmarker.setColor(yellow);
	    		eqmarker.setRadius(6);
	    	}
	    	else{
	    		eqmarker.setColor(blue);
	    		eqmarker.setRadius(3);
	    	}
	    	
	    	
	    	//adds marker to markers list
	    	markers.add(eqmarker);
	    	
	    }
	    // adds markers to the map
	    map.addMarkers(markers);	    
	    
	}
		
	// A suggested helper method that takes in an earthquake feature and 
	// returns a SimplePointMarker for that earthquake
	// TODO: Implement this method and call it from setUp, if it helps
	private SimplePointMarker createMarker(PointFeature feature)
	{
		// finish implementing and use this method, if it helps.
		
		return new SimplePointMarker(feature.getLocation());
	}
	
	public void draw() {
	    background(10);
	    map.draw();
	    addKey();
	}


	// helper method to draw key in GUI
	// TODO: Implement this method to draw the key
	private void addKey() 
	{	
		// Remember you can use Processing's graphics methods here
		// Make the box
		fill(255, 255, 255);
		rect(30, 100, 150, 300, 7);
		// Make the text strings
		textSize(12);
		String eq_key = "Earthquake Key";
		String mag_five = "5.0+ Magnitude";
		String mag_four = "4.0+ Magnitude";
		String mag_small = "Below 4.0";		
		fill(50);
		text(eq_key, 60, 110, 150, 150);
		text(mag_five, 80, 150, 150, 150);
		text(mag_four, 80, 190, 150, 150);
		text(mag_small, 80, 230, 150, 150);
		//make the ellipses for the key
		//mag five
		fill(221, 30, 8);
		ellipse(60, 157, 10, 10);
		//mag four
		fill(255, 255, 0);
		ellipse(60, 198, 6, 6);
		//mag small
		fill(8, 31, 145);
		ellipse(60, 237, 3, 3);
	}
}
