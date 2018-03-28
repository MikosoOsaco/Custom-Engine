#include "AABB.h"
#include "SingleMesh.h"


AABB::AABB(const glm::vec3 &minC, const glm::vec3 &maxC)
{
	minCorner = minC;
	maxCorner = maxC;
}

AABB::AABB(const AABB& box)
{
	minCorner = box.minCorner;
	maxCorner = box.maxCorner;
}

AABB& AABB::operator=(const AABB &box)
{
	minCorner = box.minCorner;
	maxCorner = box.maxCorner;
	return *this;
}

bool operator==(const AABB &b1, const AABB &b2)
{
	return b1.minCorner == b2.minCorner &&
		b1.maxCorner == b2.maxCorner;
}

AABB operator+(const AABB &a, const AABB &b)
{
	AABB result;
	glm::vec3 amin = a.getMinimumCorner();
	glm::vec3 amax = a.getMaximumCorner();
	glm::vec3 bmin = b.getMinimumCorner();
	glm::vec3 bmax = b.getMaximumCorner();

	result.minCorner[0] = (amin[0] < bmin[0]) ? amin[0] : bmin[0];
	result.minCorner[1] = (amin[1] < bmin[1]) ? amin[1] : bmin[1];
	result.minCorner[2] = (amin[2] < bmin[2]) ? amin[2] : bmin[2];

	result.maxCorner[0] = (amax[0] > bmax[0]) ? amax[0] : bmax[0];
	result.maxCorner[1] = (amax[1] > bmax[1]) ? amax[1] : bmax[1];
	result.maxCorner[2] = (amax[2] > bmax[2]) ? amax[2] : bmax[2];

	return result;
}


void AABB::surround(SingleMesh* mesh)
{
	bool firstSet = false;
	int ncomponents = mesh->vertDesc->GetSize();
	for (int i = 0; i < ncomponents; i++)
	{
		VertexComponent compDesc = mesh->vertDesc->GetComponent(i);
		if (compDesc.type == VertexComponent::VertexType::VERTICIES3F)
		{
			int offset = compDesc.offset;
			int inc = mesh->vertDesc->stride;
			std::vector<GLfloat> &vertList = mesh->verticesList;
			for (int j = 0; j < vertList.size(); j++) {
				if (firstSet) {
					maxCorner[0] = vertList[offset];
					maxCorner[1] = vertList[offset + 1];
					maxCorner[2] = vertList[offset + 2];
					minCorner[0] = vertList[offset];
					minCorner[1] = vertList[offset + 1];
					minCorner[2] = vertList[offset + 2];
					firstSet = false;
				}
				else {
					if (vertList[offset] > maxCorner[0]) maxCorner[0] = vertList[offset];
					if (vertList[offset + 1] > maxCorner[1]) maxCorner[1] = vertList[offset + 1];
					if (vertList[offset + 2] > maxCorner[2]) maxCorner[2] = vertList[offset + 2];

					if (vertList[offset] < minCorner[0]) minCorner[0] = vertList[offset];
					if (vertList[offset + 1] < minCorner[1]) minCorner[1] = vertList[offset + 1];
					if (vertList[offset + 2] < minCorner[2]) minCorner[2] = vertList[offset + 2];
				}
				offset += inc;
			}
		}
	}
}

bool AABB::intersects(const AABB &box) const
{
	///////////////////////////////////////////////////////////////
	// We perform some simple checks that eliminate the possibility
	// of overlap.  If we cannot eliminate the possibility of overlap
	// then we conclude they must overlap.
	///////////////////////////////////////////////////////////////
	if (((glm::vec3)minCorner)[0] > ((AABB&)box).maxCorner[0]) return false;
	if (((glm::vec3)minCorner)[1] > ((AABB&)box).maxCorner[1]) return false;
	if (((glm::vec3)minCorner)[2] > ((AABB&)box).maxCorner[2]) return false;

	if (((glm::vec3)maxCorner)[0] < ((AABB&)box).minCorner[0]) return false;
	if (((glm::vec3)maxCorner)[1] < ((AABB&)box).minCorner[1]) return false;
	if (((glm::vec3)maxCorner)[2] < ((AABB&)box).minCorner[2]) return false;

	return true;
}


glm::vec3 AABB::getMinimumCorner() const
{
	return minCorner;
}

glm::vec3 AABB::getMaximumCorner() const
{
	return maxCorner;
}

glm::vec3 AABB::getPositiveVertex(glm::vec3 &norm)
{
	glm::vec3 result(minCorner);

	if (norm[0] > 0) result[0] = maxCorner[0];
	if (norm[1] > 0) result[1] = maxCorner[1];
	if (norm[2] > 0) result[2] = maxCorner[2];

	return result;
}

glm::vec3 AABB::getNegativeVertex(glm::vec3 &norm)
{
	glm::vec3 result(minCorner);

	if (norm[0] < 0) result[0] = maxCorner[0];
	if (norm[1] < 0) result[1] = maxCorner[1];
	if (norm[2] < 0) result[2] = maxCorner[2];

	return result;
}

AABB AABB::movedBy(const glm::vec3 &amt) const
{
	AABB result(*this);
	result.minCorner = result.minCorner + amt;
	result.maxCorner = result.maxCorner + amt;
	return result;
}