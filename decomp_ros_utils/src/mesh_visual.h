#ifndef MESH_VISUAL_H
#define MESH_VISUAL_H

#include <decomp_util/data_type.h>

// BAD HEADER
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma GCC diagnostic ignored "-Wignored-attributes"
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#include <Eigen/Eigenvalues>
#pragma GCC diagnostic pop
// END BAD HEADER

#include <OGRE/OgreVector3.h>
#include <OGRE/OgreSceneNode.h>
#include <OGRE/OgreSceneManager.h>

#include <rviz/ogre_helpers/mesh_shape.h>

namespace decomp_rviz_plugins {
  class MeshVisual {
    public:
      MeshVisual(Ogre::SceneManager *scene_manager, Ogre::SceneNode *parent_node);

      virtual ~MeshVisual();

      void setMessage(const BoundVec3f &bds, const std::vector<bool>& passes = std::vector<bool>());
      void setFramePosition(const Ogre::Vector3 &position);
      void setFrameOrientation(const Ogre::Quaternion &orientation);

      void setColor(float r, float g, float b, float a);

    private:
      std::unique_ptr<rviz::MeshShape> obj_;
      std::unique_ptr<rviz::MeshShape> wall_;

      Ogre::SceneNode *frame_node_;

      Ogre::SceneManager *scene_manager_;
  };
}

#endif
