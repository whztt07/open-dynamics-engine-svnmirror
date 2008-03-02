/*************************************************************************
 *									 *
 * Open Dynamics Engine, Copyright (C) 2001,2002 Russell L. Smith.	 *
 * All rights reserved.  Email: russ@q12.org   Web: www.q12.org 	 *
 *									 *
 * This library is free software; you can redistribute it and/or	 *
 * modify it under the terms of EITHER: 				 *
 *   (1) The GNU Lesser General Public License as published by the Free  *
 *	 Software Foundation; either version 2.1 of the License, or (at  *
 *	 your option) any later version. The text of the GNU Lesser	 *
 *	 General Public License is included with this library in the	 *
 *	 file LICENSE.TXT.						 *
 *   (2) The BSD-style license that is included with this library in	 *
 *	 the file LICENSE-BSD.TXT.					 *
 *									 *
 * This library is distributed in the hope that it will be useful,	 *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of	 *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the files	 *
 * LICENSE.TXT and LICENSE-BSD.TXT for more details.			 *
 *									 *
 *************************************************************************/

/* C++ interface for non-collision stuff */


#ifndef _ODE_ODECPP_H_
#define _ODE_ODECPP_H_
#ifdef __cplusplus

#include <ode/error.h>


class dWorld {
  dWorldID _id;

  // intentionally undefined, don't use these
  dWorld (const dWorld &);
  void operator= (const dWorld &);

public:
  dWorld()
    { _id = dWorldCreate(); }
  ~dWorld()
    { dWorldDestroy (_id); }

  dWorldID id() const
    { return _id; }
  operator dWorldID() const
    { return _id; }

  void setGravity (dReal x, dReal y, dReal z)
    { dWorldSetGravity (_id,x,y,z); }
  void getGravity (dVector3 g) const
    { dWorldGetGravity (_id,g); }

  void setERP (dReal erp)
    { dWorldSetERP(_id, erp); }
  dReal getERP() const
    { return dWorldGetERP(_id); }

  void setCFM (dReal cfm)
    { dWorldSetCFM(_id, cfm); }
  dReal getCFM() const
    { return dWorldGetCFM(_id); }

  void step (dReal stepsize)
    { dWorldStep (_id,stepsize); }

  void stepFast1 (dReal stepsize, int maxiterations)
    { dWorldStepFast1 (_id,stepsize,maxiterations); }
  void setAutoEnableDepthSF1(dWorldID, int depth)
    { dWorldSetAutoEnableDepthSF1 (_id, depth); }
  int getAutoEnableDepthSF1(dWorldID) const
    { return dWorldGetAutoEnableDepthSF1 (_id); }

  void quickStep(dReal stepsize)
    { dWorldQuickStep (_id, stepsize); }
  void setQuickStepNumIterations(int num)
    { dWorldSetQuickStepNumIterations (_id, num); }
  int getQuickStepNumIterations() const
    { return dWorldGetQuickStepNumIterations (_id); }
  void setQuickStepW(dReal over_relaxation)
    { dWorldSetQuickStepW (_id, over_relaxation); }
  dReal getQuickStepW() const
    { return dWorldGetQuickStepW (_id); }

  void  setAutoDisableLinearThreshold (dReal threshold) 
    { dWorldSetAutoDisableLinearThreshold (_id,threshold); }
  dReal getAutoDisableLinearThreshold() const
    { return dWorldGetAutoDisableLinearThreshold (_id); }
  void setAutoDisableAngularThreshold (dReal threshold)
    { dWorldSetAutoDisableAngularThreshold (_id,threshold); }
  dReal getAutoDisableAngularThreshold() const
    { return dWorldGetAutoDisableAngularThreshold (_id); }
  void setAutoDisableSteps (int steps)
    { dWorldSetAutoDisableSteps (_id,steps); }
  int getAutoDisableSteps() const
    { return dWorldGetAutoDisableSteps (_id); }
  void setAutoDisableTime (dReal time)
    { dWorldSetAutoDisableTime (_id,time); }
  dReal getAutoDisableTime() const
    { return dWorldGetAutoDisableTime (_id); }
  void setAutoDisableFlag (int do_auto_disable)
    { dWorldSetAutoDisableFlag (_id,do_auto_disable); }
  int getAutoDisableFlag() const
    { return dWorldGetAutoDisableFlag (_id); }

  dReal getLinearDampingThreshold() const
    { return dWorldGetLinearDampingThreshold(_id); }
  void setLinearDampingThreshold(dReal threshold)
    { dWorldSetLinearDampingThreshold(_id, threshold); }
  dReal getAngularDampingThreshold() const
    { return dWorldGetAngularDampingThreshold(_id); }
  void setAngularDampingThreshold(dReal threshold)
    { dWorldSetAngularDampingThreshold(_id, threshold); }
  dReal getLinearDamping() const
    { return dWorldGetLinearDamping(_id); }
  void setLinearDamping(dReal scale)
    { dWorldSetLinearDamping(_id, scale); }
  dReal getAngularDamping() const
    { return dWorldGetAngularDamping(_id); }
  void setAngularDamping(dReal scale)
    { dWorldSetAngularDamping(_id, scale); }
  void setDamping(dReal linear_scale, dReal angular_scale)
    { dWorldSetDamping(_id, linear_scale, angular_scale); }

  dReal getMaxAngularSpeed() const
    { return dWorldGetMaxAngularSpeed(_id); }
  void setMaxAngularSpeed(dReal max_speed)
    { dWorldSetMaxAngularSpeed(_id, max_speed); }

  void setContactSurfaceLayer(dReal depth)
    { dWorldSetContactSurfaceLayer (_id, depth); }
  dReal getContactSurfaceLayer() const
    { return dWorldGetContactSurfaceLayer (_id); }

  void impulseToForce (dReal stepsize, dReal ix, dReal iy, dReal iz,
		       dVector3 force)
    { dWorldImpulseToForce (_id,stepsize,ix,iy,iz,force); }
};


class dBody {
  dBodyID _id;

  // intentionally undefined, don't use these
  dBody (const dBody &);
  void operator= (const dBody &);

public:
  dBody()
    { _id = 0; }
  dBody (dWorldID world)
    { _id = dBodyCreate (world); }
  ~dBody()
    { if (_id) dBodyDestroy (_id); }

  void create (dWorldID world) {
    if (_id) dBodyDestroy (_id);
    _id = dBodyCreate (world);
  }

  dBodyID id() const
    { return _id; }
  operator dBodyID() const
    { return _id; }

  void setData (void *data)
    { dBodySetData (_id,data); }
  void *getData() const
    { return dBodyGetData (_id); }

  void setPosition (dReal x, dReal y, dReal z)
    { dBodySetPosition (_id,x,y,z); }
  void setRotation (const dMatrix3 R)
    { dBodySetRotation (_id,R); }
  void setQuaternion (const dQuaternion q)
    { dBodySetQuaternion (_id,q); }
  void setLinearVel  (dReal x, dReal y, dReal z)
    { dBodySetLinearVel (_id,x,y,z); }
  void setAngularVel (dReal x, dReal y, dReal z)
    { dBodySetAngularVel (_id,x,y,z); }

  const dReal * getPosition() const
    { return dBodyGetPosition (_id); }
  const dReal * getRotation() const
    { return dBodyGetRotation (_id); }
  const dReal * getQuaternion() const
    { return dBodyGetQuaternion (_id); }
  const dReal * getLinearVel() const
    { return dBodyGetLinearVel (_id); }
  const dReal * getAngularVel() const
    { return dBodyGetAngularVel (_id); }

  void setMass (const dMass *mass)
    { dBodySetMass (_id,mass); }
  void getMass (dMass *mass) const
    { dBodyGetMass (_id,mass); }

  void addForce (dReal fx, dReal fy, dReal fz)
    { dBodyAddForce (_id, fx, fy, fz); }
  void addTorque (dReal fx, dReal fy, dReal fz)
    { dBodyAddTorque (_id, fx, fy, fz); }
  void addRelForce (dReal fx, dReal fy, dReal fz)
    { dBodyAddRelForce (_id, fx, fy, fz); }
  void addRelTorque (dReal fx, dReal fy, dReal fz)
    { dBodyAddRelTorque (_id, fx, fy, fz); }
  void addForceAtPos (dReal fx, dReal fy, dReal fz,
		      dReal px, dReal py, dReal pz)
    { dBodyAddForceAtPos (_id, fx, fy, fz, px, py, pz); }
  void addForceAtRelPos (dReal fx, dReal fy, dReal fz,
		      dReal px, dReal py, dReal pz)
    { dBodyAddForceAtRelPos (_id, fx, fy, fz, px, py, pz); }
  void addRelForceAtPos (dReal fx, dReal fy, dReal fz,
			 dReal px, dReal py, dReal pz)
    { dBodyAddRelForceAtPos (_id, fx, fy, fz, px, py, pz); }
  void addRelForceAtRelPos (dReal fx, dReal fy, dReal fz,
			    dReal px, dReal py, dReal pz)
    { dBodyAddRelForceAtRelPos (_id, fx, fy, fz, px, py, pz); }

  const dReal * getForce() const
    { return dBodyGetForce(_id); }
  const dReal * getTorque() const
    { return dBodyGetTorque(_id); }
  void setForce (dReal x, dReal y, dReal z)
    { dBodySetForce (_id,x,y,z); }
  void setTorque (dReal x, dReal y, dReal z)
    { dBodySetTorque (_id,x,y,z); }

  void enable()
    { dBodyEnable (_id); }
  void disable()
    { dBodyDisable (_id); }
  int isEnabled() const
    { return dBodyIsEnabled (_id); }

  void getRelPointPos (dReal px, dReal py, dReal pz, dVector3 result) const
    { dBodyGetRelPointPos (_id, px, py, pz, result); }
  void getRelPointVel (dReal px, dReal py, dReal pz, dVector3 result) const
    { dBodyGetRelPointVel (_id, px, py, pz, result); }
  void getPointVel (dReal px, dReal py, dReal pz, dVector3 result) const
    { dBodyGetPointVel (_id,px,py,pz,result); }
  void getPosRelPoint (dReal px, dReal py, dReal pz, dVector3 result) const
    { dBodyGetPosRelPoint (_id,px,py,pz,result); }
  void vectorToWorld (dReal px, dReal py, dReal pz, dVector3 result) const
    { dBodyVectorToWorld (_id,px,py,pz,result); }
  void vectorFromWorld (dReal px, dReal py, dReal pz, dVector3 result) const
    { dBodyVectorFromWorld (_id,px,py,pz,result); }

  void setFiniteRotationMode (int mode)
    { dBodySetFiniteRotationMode (_id, mode); }
  void setFiniteRotationAxis (dReal x, dReal y, dReal z)
    { dBodySetFiniteRotationAxis (_id, x, y, z); }

  int getFiniteRotationMode() const
    { return dBodyGetFiniteRotationMode (_id); }
  void getFiniteRotationAxis (dVector3 result) const
    { dBodyGetFiniteRotationAxis (_id, result); }

  int getNumJoints() const
    { return dBodyGetNumJoints (_id); }
  dJointID getJoint (int index) const
    { return dBodyGetJoint (_id, index); }

  void setGravityMode (int mode)
    { dBodySetGravityMode (_id,mode); }
  int getGravityMode() const
    { return dBodyGetGravityMode (_id); }

  int isConnectedTo (dBodyID body) const
    { return dAreConnected (_id, body); }

  void  setAutoDisableLinearThreshold (dReal threshold) 
    { dBodySetAutoDisableLinearThreshold (_id,threshold); }
  dReal getAutoDisableLinearThreshold() const
    { return dBodyGetAutoDisableLinearThreshold (_id); }
  void setAutoDisableAngularThreshold (dReal threshold)
    { dBodySetAutoDisableAngularThreshold (_id,threshold); }
  dReal getAutoDisableAngularThreshold() const
    { return dBodyGetAutoDisableAngularThreshold (_id); }
  void setAutoDisableSteps (int steps)
    { dBodySetAutoDisableSteps (_id,steps); }
  int getAutoDisableSteps() const
    { return dBodyGetAutoDisableSteps (_id); }
  void setAutoDisableTime (dReal time)
    { dBodySetAutoDisableTime (_id,time); }
  dReal getAutoDisableTime() const
    { return dBodyGetAutoDisableTime (_id); }
  void setAutoDisableFlag (int do_auto_disable)
    { dBodySetAutoDisableFlag (_id,do_auto_disable); }
  int getAutoDisableFlag() const
    { return dBodyGetAutoDisableFlag (_id); }

  dReal getLinearDamping() const
    { return dBodyGetLinearDamping(_id); }
  void setLinearDamping(dReal scale)
    { dBodySetLinearDamping(_id, scale); }
  dReal getAngularDamping() const
    { return dBodyGetAngularDamping(_id); }
  void setAngularDamping(dReal scale)
    { dBodySetAngularDamping(_id, scale); }
  void setDamping(dReal linear_scale, dReal angular_scale)
    { dBodySetDamping(_id, linear_scale, angular_scale); }
   dReal getLinearDampingThreshold() const
    { return dBodyGetLinearDampingThreshold(_id); }
   void setLinearDampingThreshold(dReal threshold) const
    { dBodySetLinearDampingThreshold(_id, threshold); }
   dReal getAngularDampingThreshold() const
    { return dBodyGetAngularDampingThreshold(_id); }
   void setAngularDampingThreshold(dReal threshold)
    { dBodySetAngularDampingThreshold(_id, threshold); }
   void setDampingDefaults()
    { dBodySetDampingDefaults(_id); }

   dReal getMaxAngularSpeed() const
    { return dBodyGetMaxAngularSpeed(_id); }
   void setMaxAngularSpeed(dReal max_speed)
    { dBodySetMaxAngularSpeed(_id, max_speed); }

};


class dJointGroup {
  dJointGroupID _id;

  // intentionally undefined, don't use these
  dJointGroup (const dJointGroup &);
  void operator= (const dJointGroup &);

public:
  dJointGroup (int dummy_arg=0)
    { _id = dJointGroupCreate (0); }
  ~dJointGroup()
    { dJointGroupDestroy (_id); }
  void create (int dummy_arg=0) {
    if (_id) dJointGroupDestroy (_id);
    _id = dJointGroupCreate (0);
  }

  dJointGroupID id() const
    { return _id; }
  operator dJointGroupID() const
    { return _id; }

  void empty()
    { dJointGroupEmpty (_id); }
};


class dJoint {
private:
  // intentionally undefined, don't use these
  dJoint (const dJoint &) ;
  void operator= (const dJoint &);

protected:
  dJointID _id;

public:
  dJoint()
    { _id = 0; }
  virtual ~dJoint() // :( Destructor must be virtual to suppress compiler warning "class XXX has virtual functions but non-virtual destructor"
    { if (_id) dJointDestroy (_id); }

  dJointID id() const
    { return _id; }
  operator dJointID() const
    { return _id; }

  void attach (dBodyID body1, dBodyID body2)
    { dJointAttach (_id, body1, body2); }

  void setData (void *data)
    { dJointSetData (_id, data); }
  void *getData() const
    { return dJointGetData (_id); }

  int getType() const
    { return dJointGetType (_id); }

  dBodyID getBody (int index) const
    { return dJointGetBody (_id, index); }

  void setFeedback(dJointFeedback *fb)
    { dJointSetFeedback(_id, fb); }
  dJointFeedback *getFeedback() const
    { return dJointGetFeedback(_id); }

  // If not implemented it will do nothing as describe in the doc
  virtual void setParam (int, dReal) {};
  virtual dReal getParam (int) const { return 0; }
};


class dBallJoint : public dJoint {
private:
  // intentionally undefined, don't use these
  dBallJoint (const dBallJoint &);
  void operator= (const dBallJoint &);

public:
  dBallJoint() { }
  dBallJoint (dWorldID world, dJointGroupID group=0)
    { _id = dJointCreateBall (world, group); }

  void create (dWorldID world, dJointGroupID group=0) {
    if (_id) dJointDestroy (_id);
    _id = dJointCreateBall (world, group);
  }

  void setAnchor (dReal x, dReal y, dReal z)
    { dJointSetBallAnchor (_id, x, y, z); }
  void getAnchor (dVector3 result) const
    { dJointGetBallAnchor (_id, result); }
  void getAnchor2 (dVector3 result) const
    { dJointGetBallAnchor2 (_id, result); }
  virtual void setParam (int parameter, dReal value)
    { dJointSetBallParam (_id, parameter, value); }
  virtual dReal getParam (int parameter) const
    { return dJointGetBallParam (_id, parameter); }
} ;


class dHingeJoint : public dJoint {
  // intentionally undefined, don't use these
  dHingeJoint (const dHingeJoint &);
  void operator = (const dHingeJoint &);

public:
  dHingeJoint() { }
  dHingeJoint (dWorldID world, dJointGroupID group=0)
    { _id = dJointCreateHinge (world, group); }

  void create (dWorldID world, dJointGroupID group=0) {
    if (_id) dJointDestroy (_id);
    _id = dJointCreateHinge (world, group);
  }

  void setAnchor (dReal x, dReal y, dReal z)
    { dJointSetHingeAnchor (_id, x, y, z); }
  void getAnchor (dVector3 result) const
    { dJointGetHingeAnchor (_id, result); }
  void getAnchor2 (dVector3 result) const
    { dJointGetHingeAnchor2 (_id, result); }

  void setAxis (dReal x, dReal y, dReal z)
    { dJointSetHingeAxis (_id, x, y, z); }
  void getAxis (dVector3 result) const
    { dJointGetHingeAxis (_id, result); }

  dReal getAngle() const
    { return dJointGetHingeAngle (_id); }
  dReal getAngleRate() const
    { return dJointGetHingeAngleRate (_id); }

  virtual void setParam (int parameter, dReal value)
    { dJointSetHingeParam (_id, parameter, value); }
  virtual dReal getParam (int parameter) const
    { return dJointGetHingeParam (_id, parameter); }

  void addTorque (dReal torque)
	{ dJointAddHingeTorque(_id, torque); }
};


class dSliderJoint : public dJoint {
  // intentionally undefined, don't use these
  dSliderJoint (const dSliderJoint &);
  void operator = (const dSliderJoint &);

public:
  dSliderJoint() { }
  dSliderJoint (dWorldID world, dJointGroupID group=0)
    { _id = dJointCreateSlider (world, group); }

  void create (dWorldID world, dJointGroupID group=0) {
    if (_id) dJointDestroy (_id);
    _id = dJointCreateSlider (world, group);
  }

  void setAxis (dReal x, dReal y, dReal z)
    { dJointSetSliderAxis (_id, x, y, z); }
  void getAxis (dVector3 result) const
    { dJointGetSliderAxis (_id, result); }

  dReal getPosition() const
    { return dJointGetSliderPosition (_id); }
  dReal getPositionRate() const
    { return dJointGetSliderPositionRate (_id); }

  virtual void setParam (int parameter, dReal value)
    { dJointSetSliderParam (_id, parameter, value); }
  virtual dReal getParam (int parameter) const
    { return dJointGetSliderParam (_id, parameter); }

  void addForce (dReal force)
	{ dJointAddSliderForce(_id, force); }
};


class dUniversalJoint : public dJoint {
  // intentionally undefined, don't use these
  dUniversalJoint (const dUniversalJoint &);
  void operator = (const dUniversalJoint &);

public:
  dUniversalJoint() { }
  dUniversalJoint (dWorldID world, dJointGroupID group=0)
    { _id = dJointCreateUniversal (world, group); }

  void create (dWorldID world, dJointGroupID group=0) {
    if (_id) dJointDestroy (_id);
    _id = dJointCreateUniversal (world, group);
  }

  void setAnchor (dReal x, dReal y, dReal z)
    { dJointSetUniversalAnchor (_id, x, y, z); }
  void setAxis1 (dReal x, dReal y, dReal z)
    { dJointSetUniversalAxis1 (_id, x, y, z); }
  void setAxis2 (dReal x, dReal y, dReal z)
    { dJointSetUniversalAxis2 (_id, x, y, z); }
  virtual void setParam (int parameter, dReal value)
    { dJointSetUniversalParam (_id, parameter, value); }

  void getAnchor (dVector3 result) const
    { dJointGetUniversalAnchor (_id, result); }
  void getAnchor2 (dVector3 result) const
    { dJointGetUniversalAnchor2 (_id, result); }
  void getAxis1 (dVector3 result) const
    { dJointGetUniversalAxis1 (_id, result); }
  void getAxis2 (dVector3 result) const
    { dJointGetUniversalAxis2 (_id, result); }
  virtual dReal getParam (int parameter) const
    { return dJointGetUniversalParam (_id, parameter); }
  void getAngles(dReal *angle1, dReal *angle2) const
    { dJointGetUniversalAngles (_id, angle1, angle2); }

  dReal getAngle1() const
    { return dJointGetUniversalAngle1 (_id); }
  dReal getAngle1Rate() const
    { return dJointGetUniversalAngle1Rate (_id); }
  dReal getAngle2() const
    { return dJointGetUniversalAngle2 (_id); }
  dReal getAngle2Rate() const
    { return dJointGetUniversalAngle2Rate (_id); }

  void addTorques (dReal torque1, dReal torque2)
	{ dJointAddUniversalTorques(_id, torque1, torque2); }
};


class dHinge2Joint : public dJoint {
  // intentionally undefined, don't use these
  dHinge2Joint (const dHinge2Joint &);
  void operator = (const dHinge2Joint &);

public:
  dHinge2Joint() { }
  dHinge2Joint (dWorldID world, dJointGroupID group=0)
    { _id = dJointCreateHinge2 (world, group); }

  void create (dWorldID world, dJointGroupID group=0) {
    if (_id) dJointDestroy (_id);
    _id = dJointCreateHinge2 (world, group);
  }

  void setAnchor (dReal x, dReal y, dReal z)
    { dJointSetHinge2Anchor (_id, x, y, z); }
  void setAxis1 (dReal x, dReal y, dReal z)
    { dJointSetHinge2Axis1 (_id, x, y, z); }
  void setAxis2 (dReal x, dReal y, dReal z)
    { dJointSetHinge2Axis2 (_id, x, y, z); }

  void getAnchor (dVector3 result) const
    { dJointGetHinge2Anchor (_id, result); }
  void getAnchor2 (dVector3 result) const
    { dJointGetHinge2Anchor2 (_id, result); }
  void getAxis1 (dVector3 result) const
    { dJointGetHinge2Axis1 (_id, result); }
  void getAxis2 (dVector3 result) const
    { dJointGetHinge2Axis2 (_id, result); }

  dReal getAngle1() const
    { return dJointGetHinge2Angle1 (_id); }
  dReal getAngle1Rate() const
    { return dJointGetHinge2Angle1Rate (_id); }
  dReal getAngle2Rate() const
    { return dJointGetHinge2Angle2Rate (_id); }

  virtual void setParam (int parameter, dReal value)
    { dJointSetHinge2Param (_id, parameter, value); }
  virtual dReal getParam (int parameter) const
    { return dJointGetHinge2Param (_id, parameter); }

  void addTorques(dReal torque1, dReal torque2)
	{ dJointAddHinge2Torques(_id, torque1, torque2); }
};


class dPRJoint : public dJoint {
  dPRJoint (const dPRJoint &);
  void operator = (const dPRJoint &);

public:
  dPRJoint() { }
  dPRJoint (dWorldID world, dJointGroupID group=0)
    { _id = dJointCreatePR (world, group); }

  void create (dWorldID world, dJointGroupID group=0) {
    if (_id) dJointDestroy (_id);
    _id = dJointCreatePR (world, group);
  }

  void setAnchor (dReal x, dReal y, dReal z)
    { dJointSetPRAnchor (_id, x, y, z); }
  void setAxis1 (dReal x, dReal y, dReal z)
    { dJointSetPRAxis1 (_id, x, y, z); }
  void setAxis2 (dReal x, dReal y, dReal z)
    { dJointSetPRAxis2 (_id, x, y, z); }

  void getAnchor (dVector3 result) const
    { dJointGetPRAnchor (_id, result); }
  void getAxis1 (dVector3 result) const
    { dJointGetPRAxis1 (_id, result); }
  void getAxis2 (dVector3 result) const
    { dJointGetPRAxis2 (_id, result); }

  dReal getPosition() const
    { return dJointGetPRPosition (_id); }
  dReal getPositionRate() const
    { return dJointGetPRPositionRate (_id); }

  virtual void setParam (int parameter, dReal value)
    { dJointSetPRParam (_id, parameter, value); }
  virtual dReal getParam (int parameter) const
    { return dJointGetPRParam (_id, parameter); }
};







class dPistonJoint : public dJoint
{
  // intentionally undefined, don't use these
  dPistonJoint (const dPistonJoint &);
  void operator = (const dPistonJoint &);

public:
  dPistonJoint() { }
  dPistonJoint (dWorldID world, dJointGroupID group=0)
  { _id = dJointCreatePiston (world, group); }

  void create (dWorldID world, dJointGroupID group=0)
  {
    if (_id) dJointDestroy (_id);
    _id = dJointCreatePiston (world, group);
  }

  void setAnchor (dReal x, dReal y, dReal z)
    { dJointSetPistonAnchor (_id, x, y, z); }
  void getAnchor (dVector3 result) const
    { dJointGetPistonAnchor (_id, result); }
  void getAnchor2 (dVector3 result) const
    { dJointGetPistonAnchor2 (_id, result); }

  void setAxis (dReal x, dReal y, dReal z)
    { dJointSetPistonAxis (_id, x, y, z); }
  void getAxis (dVector3 result) const
    { dJointGetPistonAxis (_id, result); }

  dReal getPosition() const
    { return dJointGetPistonPosition (_id); }
  dReal getPositionRate() const
    { return dJointGetPistonPositionRate (_id); }

  virtual void setParam (int parameter, dReal value)
  { dJointSetPistonParam (_id, parameter, value); }
  virtual dReal getParam (int parameter) const
    { return dJointGetPistonParam (_id, parameter); }

  void addForce (dReal force)
  { dJointAddPistonForce (_id, force); }
};



class dFixedJoint : public dJoint
{
  // intentionally undefined, don't use these
  dFixedJoint (const dFixedJoint &);
  void operator = (const dFixedJoint &);

public:
  dFixedJoint() { }
  dFixedJoint (dWorldID world, dJointGroupID group=0)
    { _id = dJointCreateFixed (world, group); }

  void create (dWorldID world, dJointGroupID group=0) {
    if (_id) dJointDestroy (_id);
    _id = dJointCreateFixed (world, group);
  }

  void set()
    { dJointSetFixed (_id); }

  virtual void setParam (int parameter, dReal value)
    { dJointSetFixedParam (_id, parameter, value); }

  virtual dReal getParam (int parameter) const
    { return dJointGetFixedParam (_id, parameter); }
};


class dContactJoint : public dJoint {
  // intentionally undefined, don't use these
  dContactJoint (const dContactJoint &);
  void operator = (const dContactJoint &);

public:
  dContactJoint() { }
  dContactJoint (dWorldID world, dJointGroupID group, dContact *contact)
    { _id = dJointCreateContact (world, group, contact); }

  void create (dWorldID world, dJointGroupID group, dContact *contact) {
    if (_id) dJointDestroy (_id);
    _id = dJointCreateContact (world, group, contact);
  }
};


class dNullJoint : public dJoint {
  // intentionally undefined, don't use these
  dNullJoint (const dNullJoint &);
  void operator = (const dNullJoint &);

public:
  dNullJoint() { }
  dNullJoint (dWorldID world, dJointGroupID group=0)
    { _id = dJointCreateNull (world, group); }

  void create (dWorldID world, dJointGroupID group=0) {
    if (_id) dJointDestroy (_id);
    _id = dJointCreateNull (world, group);
  }
};


class dAMotorJoint : public dJoint {
  // intentionally undefined, don't use these
  dAMotorJoint (const dAMotorJoint &);
  void operator = (const dAMotorJoint &);

public:
  dAMotorJoint() { }
  dAMotorJoint (dWorldID world, dJointGroupID group=0)
    { _id = dJointCreateAMotor (world, group); }

  void create (dWorldID world, dJointGroupID group=0) {
    if (_id) dJointDestroy (_id);
    _id = dJointCreateAMotor (world, group);
  }

  void setMode (int mode)
    { dJointSetAMotorMode (_id, mode); }
  int getMode() const
    { return dJointGetAMotorMode (_id); }

  void setNumAxes (int num)
    { dJointSetAMotorNumAxes (_id, num); }
  int getNumAxes() const
    { return dJointGetAMotorNumAxes (_id); }

  void setAxis (int anum, int rel, dReal x, dReal y, dReal z)
    { dJointSetAMotorAxis (_id, anum, rel, x, y, z); }
  void getAxis (int anum, dVector3 result) const
    { dJointGetAMotorAxis (_id, anum, result); }
  int getAxisRel (int anum) const
    { return dJointGetAMotorAxisRel (_id, anum); }

  void setAngle (int anum, dReal angle)
    { dJointSetAMotorAngle (_id, anum, angle); }
  dReal getAngle (int anum) const
    { return dJointGetAMotorAngle (_id, anum); }
  dReal getAngleRate (int anum)
    { return dJointGetAMotorAngleRate (_id,anum); }

  void setParam (int parameter, dReal value)
    { dJointSetAMotorParam (_id, parameter, value); }
  dReal getParam (int parameter) const
    { return dJointGetAMotorParam (_id, parameter); }

  void addTorques(dReal torque1, dReal torque2, dReal torque3)
	{ dJointAddAMotorTorques(_id, torque1, torque2, torque3); }
};


class dLMotorJoint : public dJoint {
  // intentionally undefined, don't use these
  dLMotorJoint (const dLMotorJoint &);
  void operator = (const dLMotorJoint &);

public:
  dLMotorJoint() { }
  dLMotorJoint (dWorldID world, dJointGroupID group=0)
    { _id = dJointCreateLMotor (world, group); }

  void create (dWorldID world, dJointGroupID group=0) {
    if (_id) dJointDestroy (_id);
    _id = dJointCreateLMotor (world, group);
  }

  void setNumAxes (int num)
    { dJointSetLMotorNumAxes (_id, num); }
  int getNumAxes() const
    { return dJointGetLMotorNumAxes (_id); }

  void setAxis (int anum, int rel, dReal x, dReal y, dReal z)
    { dJointSetLMotorAxis (_id, anum, rel, x, y, z); }
  void getAxis (int anum, dVector3 result) const
    { dJointGetLMotorAxis (_id, anum, result); }

  void setParam (int parameter, dReal value)
    { dJointSetLMotorParam (_id, parameter, value); }
  dReal getParam (int parameter) const
    { return dJointGetLMotorParam (_id, parameter); }
};



#endif
#endif
