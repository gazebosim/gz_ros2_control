// Copyright 2023 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Lovro Ivanov lovro.ivanov@gmail.com
 * \date    2023-03-15
 *
 */
//----------------------------------------------------------------------

#ifndef IGN_ROS2_CONTROL__MIMICJOINTSYSTEM_HH_
#define IGN_ROS2_CONTROL__MIMICJOINTSYSTEM_HH_

//! [header]
#include <memory>

#include <ignition/gazebo/System.hh>

// This is an example to go in your urdf (is that correct?)
//! <plugin filename="mimic-joint-system" name="ign_ros2_control::MimicJointSystem">
//!     <joint_name>joint_name</joint_name>
//!     <mimic_joint_name>mimic_joint_name</mimic_joint_name>
//!     <multiplier>1.0</multiplier>
//!     <offset>0.0</offset>
//!     <joint_index>0</joint_index>
//!     <mimic_joint_index>0</mimic_joint_index>
//!     <p_gain>100.0</p_gain>
//!     <i_gain>0.1</i_gain>
//!     <d_gain>0.0</d_gain>
//!     <i_max>5.0</i_max>
//!     <i_min>-5.0</i_min>
//!     <cmd_max>500.0</cmd_max>
//!     <cmd_min>-500.0</cmd_min>
//!     <cmd_offset>0.0</cmd_offset>
//!     <dead_zone>0.001</dead_zone>
//!     <use_velocity_commands>false</use_velocity_commands>
//! </plugin>

namespace ign_ros2_control
{

// Forward declaration
  class MimicJointSystemPrivate;  // NOLINT

  class MimicJointSystem:  // NOLINT
// This class is a system.
  public ignition::gazebo::System,  // NOLINT
  public ignition::gazebo::ISystemConfigure,  // NOLINT
// This class also implements the ISystemPreUpdate, ISystemUpdate,
// and ISystemPostUpdate interfaces.
  public ignition::gazebo::ISystemPreUpdate,  // NOLINT
  public ignition::gazebo::ISystemUpdate,  // NOLINT
  public ignition::gazebo::ISystemPostUpdate  // NOLINT
  {
public:
    MimicJointSystem();

    // Documentation inherited

public:
    void Configure(
      const ignition::gazebo::Entity & _entity,
      const std::shared_ptr < const sdf::Element > & _sdf,
      ignition::gazebo::EntityComponentManager & _ecm,
      ignition::gazebo::EventManager & _eventMgr) override;

public:
    void PreUpdate(
      const ignition::gazebo::UpdateInfo & _info,
      ignition::gazebo::EntityComponentManager & _ecgm) override;

public:
    void Update(
      const ignition::gazebo::UpdateInfo & _info,
      ignition::gazebo::EntityComponentManager & _ecm) override;

public:
    void PostUpdate(
      const ignition::gazebo::UpdateInfo & _info,
      const ignition::gazebo::EntityComponentManager & _ecm) override;

private:
    /// \brief Private data pointer

private:
    std::unique_ptr < MimicJointSystemPrivate > dataPtr;
  };
}  // namespace ign_ros2_control
//! [header]

#endif  // IGN_ROS2_CONTROL__MIMICJOINTSYSTEM_HH_
