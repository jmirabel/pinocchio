//
// Copyright (c) 2015-2020 CNRS INRIA
// Copyright (c) 2015 Wandercraft, 86 rue de Paris 91400 Orsay, France.
//

#ifndef __pinocchio_python_python_hpp__
#define __pinocchio_python_python_hpp__

#include "pinocchio/fwd.hpp"
#include <eigenpy/eigenpy.hpp>

#define PYPINOCCHIO_DEPRECATED_ATTRIBUTE_WRAPPER(CLASS,ATTRIB) deprecated_ ## CLASS ## _ ## ATTRIB

/// \param MSG message telling what should be used instead of this attribute.
#define PYPINOCCHIO_DECL_DEPRECATED_ATTRIBUTE_WRAPPER(TYPE,CLASS,ATTRIB,MSG)                 \
struct PYPINOCCHIO_DEPRECATED_ATTRIBUTE_WRAPPER(CLASS,ATTRIB) {                              \
  static inline void warn() {                                                                \
    static bool firstTime = true;                                                            \
    if (firstTime) {                                                                         \
      firstTime = false;                                                                     \
      deprecationWarning("Attribute " #ATTRIB " of class " #CLASS " is deprecated." MSG);  \
    }                                                                                        \
  }                                                                                          \
  static inline TYPE& get(CLASS& obj) { warn(); return obj.ATTRIB; }                         \
  static inline void set(CLASS& obj, const TYPE& attr) { warn(); obj.ATTRIB = attr; }        \
}

namespace pinocchio
{
  namespace python
  {
    // Expose spatial classes
    void exposeSE3();
    void exposeForce();
    void exposeMotion();
    void exposeInertia();
    void exposeExplog();
    void exposeSkew();

    // Expose math module
    void exposeRpy();
    
    // Expose multibody classes
    void exposeJoints();
    void exposeModel();
    void exposeFrame();
    void exposeData();
    
    // Expose geometry module
    void exposeGeometry();
    
    // Expose parsers
    void exposeParsers();
    
    // Expose algorithms
    void exposeAlgorithms();
    
#ifdef PINOCCHIO_WITH_HPP_FCL_PYTHON_BINDINGS
    void exposeFCL();
#endif // PINOCCHIO_WITH_HPP_FCL_PYTHON_BINDINGS

    void deprecationWarning(const char* msg);
  } // namespace python
} // namespace pinocchio

#endif // ifndef __pinocchio_python_python_hpp__
