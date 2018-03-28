#ifndef AABB_H
#define AABB_H

#include "glm-0.9.8.4\glm\glm.hpp"
#include "glm-0.9.8.4\glm\gtc\matrix_transform.hpp"
#include "glm-0.9.8.4\glm\gtc\type_ptr.hpp"

class SingleMesh;

class AABB
{
private:
	/** The minimum corner is the back-left corner */
	glm::vec3							minCorner;
	/** The maximum corner is the front-right corner */
	glm::vec3							maxCorner;
public:
	/**
	* Create a default bounding box which is useless until you give it
	* a model to use to calculate its coordinates.
	*/
	AABB() :
		minCorner(glm::vec3(0.0f, 0.0f, 0.0f)), maxCorner(glm::vec3(0.0f, 0.0f, 0.0f))
	{}

	/**
	* Create a bounding box with the given size.
	* @param minC back left corner
	* @param maxC front right corner
	*/
	AABB(const glm::vec3 &minC, const glm::vec3 &maxC);

	/**
	* Copy Constructor
	*/
	AABB(const AABB& box);

	/**
	* Assignment operator
	*/
	AABB& operator=(const AABB &box);

	/**
	* Equality operator
	*/
	friend bool operator==(const AABB &b1, const AABB &b2);

	/**
	* This adds two bounding boxes together to yield a new bounding box which encompasses
	* both of the boxes from which it was made.  The new centre is halfway between
	* the centres of the spheres from which it was made.
	* @param a First bounding box to add
	* @param b second bounding box to add
	* @return a bounding box which encompasses the two parameters
	*/
	friend AABB operator+(const AABB &a, const AABB &b);


	/**
	* Calculate the coordinates for the bounding box so that it will
	* enclose the model which is passed to this method.
	* @param mdl The model this bounding box will enclose.
	*/
	void surround(SingleMesh* mesh);

	/**
	* Determine if two bounding boxes intersect one another.
	* @param box The box to check to determine if it intersects this box
	* @return true if the two boxes intersect
	*/
	bool intersects(const AABB &box)const;

	/**
	* Return the minimum corner.
	* @return the minimum corner
	*/
	glm::vec3 getMinimumCorner() const;

	/**
	* Return the maximum corner.
	* @return the maximum corner
	*/
	glm::vec3 getMaximumCorner() const;

	/**
	* This returns the positive vertex of the bounding box.  This is the
	* vertex which is farthest along the normal from the plane.
	* @param norn The normal to use to calculate the positive vertex.
	*/
	glm::vec3 getPositiveVertex(glm::vec3 &norm);

	/**
	* This returns the negative vertex of the bounding box.  This is the
	* vertex which is closest along the normal to the plane.
	* @param norn The normal to use to calculate the negative vertex.
	*/
	glm::vec3 getNegativeVertex(glm::vec3 &norm);

	/**
	* Return a new bounding box which is the same as this one but moved by the indicated amount.
	* @param amt the amount to move the box.
	* @return a copy of this that has been moved by the requested amount
	*/
	AABB movedBy(const glm::vec3 &amt) const;

	/*friend std::ostream& operator<<(std::ostream& a, const AABoundingBox& b);

	std::string toString() const;*/

};

#endif