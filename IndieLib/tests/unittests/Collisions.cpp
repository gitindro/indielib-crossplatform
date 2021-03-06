/*********************************** The zlib License ************************************
 *
 * Copyright (c) 2013 Indielib-crossplatform Development Team
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software
 * in a product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 *
 *****************************************************************************************/


#include "dependencies/unittest++/src/UnitTest++.h"
#include "CIndieLib.h"

TEST(pointToLineHorizontalDistanceFromMiddleIsSegment) {
	IND_Vector2 a (10.0f, 10.0f);
	IND_Vector2 b (20.0f, 10.0f);
	IND_Vector2 c (15.0f, 20.0f);
	
	CHECK_CLOSE(10.0,CIndieLib::instance()->_math->pointToLineDistance(a,b,c,true),0.1);
}

TEST(pointToLineHorizontalDistanceFromAIsSegment) {
	IND_Vector2 a (10.0f, 10.0f);
	IND_Vector2 b (20.0f, 10.0f);
	IND_Vector2 c (10.0f, 20.0f);
	
	CHECK_CLOSE(10.0,CIndieLib::instance()->_math->pointToLineDistance(a,b,c,true),0.1);
}

TEST(pointToLineHorizontaleDistanceFromBIsSegment) {
	IND_Vector2 a (10.0f, 10.0f);
	IND_Vector2 b (20.0f, 10.0f);
	IND_Vector2 c (20.0f, 20.0f);
	
	CHECK_CLOSE(10.0,CIndieLib::instance()->_math->pointToLineDistance(a,b,c,true),0.1);
}

TEST(pointToLineHorizontalDistanceFromMiddleIsSegmentInverted) {
	IND_Vector2 a (20.0f, 10.0f);
	IND_Vector2 b (10.0f, 10.0f);
	IND_Vector2 c (15.0f, 20.0f);
	
	CHECK_CLOSE(10.0,CIndieLib::instance()->_math->pointToLineDistance(a,b,c,true),0.1);
}

TEST(pointToLineHorizontalDistanceFromAIsSegmentInverted) {
	IND_Vector2 a (20.0f, 10.0f);
	IND_Vector2 b (10.0f, 10.0f);
	IND_Vector2 c (15.0f, 20.0f);
	
	CHECK_CLOSE(10.0,CIndieLib::instance()->_math->pointToLineDistance(a,b,c,true),0.1);
}

TEST(pointToLineHorizontalDistanceFromBIsSegmentInverted) {
	IND_Vector2 a (20.0f, 10.0f);
	IND_Vector2 b (10.0f, 10.0f);
	IND_Vector2 c (15.0f, 20.0f);
	
	CHECK_CLOSE(10.0,CIndieLib::instance()->_math->pointToLineDistance(a,b,c,true),0.1);
}

TEST(pointToLineDistanceFromMiddleNotSegment) {
	IND_Vector2 a (10.0f, 10.0f);
	IND_Vector2 b (20.0f, 10.0f);
	IND_Vector2 c (20.0f, 20.0f);
	
	CHECK_CLOSE(10.0,CIndieLib::instance()->_math->pointToLineDistance(a,b,c,false),0.1);
}

TEST(pointToLineDistanceFromMiddleFarRightNotSegment) {
	IND_Vector2 a (10.0f, 10.0f);
	IND_Vector2 b (20.0f, 10.0f);
	IND_Vector2 c (150.0f, 20.0f);
	
	CHECK_CLOSE(10.0,CIndieLib::instance()->_math->pointToLineDistance(a,b,c,false),0.1);
}

TEST(pointToLineDistanceFromMiddleFarLeftNotSegment) {
	IND_Vector2 a (10.0f, 10.0f);
	IND_Vector2 b (20.0f, 10.0f);
	IND_Vector2 c (-150.0f, 20.0f);
	
	CHECK_CLOSE(10.0,CIndieLib::instance()->_math->pointToLineDistance(a,b,c,false),0.1);
}

TEST(segmentIntersectioncrossedyes) {
	IND_Vector2 a (10.0f, 10.0f);
	IND_Vector2 b (20.0f, 20.0f);
	IND_Vector2 c (10.0f, 20.0f);
	IND_Vector2 d (20.0f, 10.0f);

	CHECK_EQUAL(true,CIndieLib::instance()->_math->isSegmentIntersection(a,b,c,d));

}

TEST(segmentIntersectionperpendicularyes) {
	IND_Vector2 a (10.0f, 10.0f);
	IND_Vector2 b (20.0f, 10.0f);
	IND_Vector2 c (15.0f, 15.0f);
	IND_Vector2 d (15.0f, 5.0f);

	CHECK_EQUAL(true,CIndieLib::instance()->_math->isSegmentIntersection(a,b,c,d));

}

TEST(segmentIntersectionnot) {
	IND_Vector2 a (10.0f, 10.0f);
	IND_Vector2 b (20.0f, 20.0f);
	IND_Vector2 c (-10.0f, -10.0f);
	IND_Vector2 d (-20.0f, -20.0f);

	CHECK_EQUAL(false,CIndieLib::instance()->_math->isSegmentIntersection(a,b,c,d));

}

TEST(isPointInsideTriangleInside) {	
	IND_Vector2 a = IND_Vector2(0.0f,0.0f);
	IND_Vector2 b = IND_Vector2(30.0f,0.0f);
	IND_Vector2 c = IND_Vector2(15.0f,30.0f);
	IND_Vector2 pointInside = IND_Vector2(15.0f,1.0f);

	CHECK_EQUAL(true,CIndieLib::instance()->_math->isPointInsideTriangle(pointInside,a,b,c));
}	

TEST(isPointInsideTriangleInsideCloseVertex1) {	
	IND_Vector2 a = IND_Vector2(0.0f,0.0f);
	IND_Vector2 b = IND_Vector2(30.0f,0.0f);
	IND_Vector2 c = IND_Vector2(15.0f,30.0f);
	IND_Vector2 pointInside = IND_Vector2(29.9f,0.1f);

	CHECK_EQUAL(true,CIndieLib::instance()->_math->isPointInsideTriangle(pointInside,a,b,c));
}	

TEST(isPointInsideTriangleInsideCloseVertex2) {	
	IND_Vector2 a = IND_Vector2(0.0f,0.0f);
	IND_Vector2 b = IND_Vector2(30.0f,0.0f);
	IND_Vector2 c = IND_Vector2(15.0f,30.0f);
	IND_Vector2 pointInside = IND_Vector2(29.9f,0.1f);

	CHECK_EQUAL(true,CIndieLib::instance()->_math->isPointInsideTriangle(pointInside,a,b,c));
}	

TEST(isPointInsideTriangleInsideCloseVertex3) {	
	IND_Vector2 a = IND_Vector2(0.0f,0.0f);
	IND_Vector2 b = IND_Vector2(30.0f,0.0f);
	IND_Vector2 c = IND_Vector2(15.0f,30.0f);
	IND_Vector2 pointInside = IND_Vector2(0.1f,0.1f);

	CHECK_EQUAL(true,CIndieLib::instance()->_math->isPointInsideTriangle(pointInside,a,b,c));
}	

TEST(isPointInsideTriangleOutsideRightFar) {	
	IND_Vector2 a = IND_Vector2(0.0f,0.0f);
	IND_Vector2 b = IND_Vector2(30.0f,0.0f);
	IND_Vector2 c = IND_Vector2(15.0f,30.0f);
	IND_Vector2 pointInside = IND_Vector2(150.0f,1.0f);

	CHECK_EQUAL(false,CIndieLib::instance()->_math->isPointInsideTriangle(pointInside,a,b,c));
}

TEST(isPointInsideTriangleOutsideRightClose) {	
	IND_Vector2 a = IND_Vector2(0.0f,0.0f);
	IND_Vector2 b = IND_Vector2(30.0f,0.0f);
	IND_Vector2 c = IND_Vector2(15.0f,30.0f);
	IND_Vector2 pointInside = IND_Vector2(30.1f,0.0f);

	CHECK_EQUAL(false,CIndieLib::instance()->_math->isPointInsideTriangle(pointInside,a,b,c));
}

TEST(isPointInsideTriangleOutsideTopFar) {	
	IND_Vector2 a = IND_Vector2(0.0f,0.0f);
	IND_Vector2 b = IND_Vector2(30.0f,0.0f);
	IND_Vector2 c = IND_Vector2(15.0f,30.0f);
	IND_Vector2 pointInside = IND_Vector2(15.0f,150.0f);

	CHECK_EQUAL(false,CIndieLib::instance()->_math->isPointInsideTriangle(pointInside,a,b,c));
}

TEST(isPointInsideTriangleOutsideTopClose) {	
	IND_Vector2 a = IND_Vector2(0.0f,0.0f);
	IND_Vector2 b = IND_Vector2(30.0f,0.0f);
	IND_Vector2 c = IND_Vector2(15.0f,30.0f);
	IND_Vector2 pointInside = IND_Vector2(15.0f,30.1f);

	CHECK_EQUAL(false,CIndieLib::instance()->_math->isPointInsideTriangle(pointInside,a,b,c));
}

TEST(isPointInsideTriangleOutsideLeftFar) {	
	IND_Vector2 a = IND_Vector2(0.0f,0.0f);
	IND_Vector2 b = IND_Vector2(30.0f,0.0f);
	IND_Vector2 c = IND_Vector2(15.0f,30.0f);
	IND_Vector2 pointInside = IND_Vector2(-15.0f,0.0f);

	CHECK_EQUAL(false,CIndieLib::instance()->_math->isPointInsideTriangle(pointInside,a,b,c));
}

TEST(isPointInsideTriangleOutsideLeftClose) {	
	IND_Vector2 a = IND_Vector2(0.0f,0.0f);
	IND_Vector2 b = IND_Vector2(30.0f,0.0f);
	IND_Vector2 c = IND_Vector2(15.0f,30.0f);
	IND_Vector2 pointInside = IND_Vector2(-0.1f,0.0f);

	CHECK_EQUAL(false,CIndieLib::instance()->_math->isPointInsideTriangle(pointInside,a,b,c));
}