#ifndef ELLIPSOIDS_VISUAL_H
#define ELLIPSOIDS_VISUAL_H

#include <decomp_ros_msgs/Ellipsoids.h>
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

#include <rviz/ogre_helpers/shape.h>

namespace decomp_rviz_plugins {
  class EllipsoidsVisual {
    public:
      EllipsoidsVisual(Ogre::SceneManager *scene_manager,
                       Ogre::SceneNode *parent_node);

      virtual ~EllipsoidsVisual();

      void setMessage(const decomp_ros_msgs::Ellipsoids::ConstPtr &msg);

      void setFramePosition(const Ogre::Vector3 &position);
      void setFrameOrientation(const Ogre::Quaternion &orientation);

      void setColor(float r, float g, float b, float a);

    private:
      std::vector<std::unique_ptr<rviz::Shape>> objs_;

      Ogre::SceneNode *frame_node_;

      Ogre::SceneManager *scene_manager_;
  };
}
#endif
