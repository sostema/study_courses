package guimodule;

import processing.core.PApplet;
import processing.core.PShape;

public class MyDisplay extends PApplet{
	
	PShape dog, head, body, leg1, leg2, leg3, leg4, tail;
	
	public void setup(){
		size(600, 600);
		background(240, 240,240);
		
		//create shape group
		dog = createShape(GROUP);
		
		//make the dog parts
		head = createShape(ELLIPSE, 250, 250, 50, 50);
		head.setFill(color(60));
		body = createShape(RECT, 150, 275, 100, 50);
		body.setFill(color(60));
		leg1 = createShape(LINE, 150, 325, 145, 350);
		leg2 = createShape(LINE, 150, 325, 155, 350);
		leg3 = createShape(LINE, 250, 325, 245, 350);
		leg4 = createShape(LINE, 250, 325, 255, 350);
		tail = createShape(LINE, 150, 275, 100, 250);
		
		// add parts to parent group
		dog.addChild(head);
		dog.addChild(body);
		dog.addChild(leg1);
		dog.addChild(leg2);
		dog.addChild(leg3);
		dog.addChild(leg4);
		dog.addChild(tail);
		
	}
	
	public void draw(){
		background(204);
		translate(50, 15);
		shape(dog);
	}
}
