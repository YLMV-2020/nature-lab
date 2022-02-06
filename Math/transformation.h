#ifndef TRANSFORMATION_H
#define TRANSFORMATION_H




bool transformation_test();

class __declspec(dllexport) transformation {
private:
public:
    float	m_a[4][4]; /** matrix element, first index is row, second index is column */
    /** default constructor */
    transformation();

    /**
     @brief converts this transformation to OpenGL matrix
     @param[out] val column-major output (i.e. an OpenGL matrix)
     */
    void to_opengl(float* val);

    /**
     @brief initalizes this transformation from an OpenGL matrix
     @param[in] val column-major input from which to set this transformation
     */
    void from_opengl(float* val);


    /**
     @brief returns the right, up and forward vectors for this transformation
     and the translation
     @param[out] r local "right" vector
     @param[out] u local "up" vector
     @param[out] f local "forward" vector
     @param[out] p positions/translation
     */
    void get_right_up_forward_position(float* r, float* u, float* f, float* p);

    /**
     @brief construct a transformation by setting the right, up, forward and
     translation vectors, with the fourth row [0, 0, 0, 1]
     @param[in] r right vector
     @param[in] u up vector
     @param[in] f forward vector
     @param[in] t translation vector
    */
    void set_right_up_forward_position(float* r, float* u, float* f, float* p);

    /**
     @brief performs a Gram-Schmidt orthogonalization on the rotation matrix
     portion of the transformation matrix. This completely ignores (and so
     destroys) any scaling, shearing or perspective projection that has been
     applied, but can be used to help reduce the effect of repeated roundoff
     errors accumulating on repeated operations
    */
    void reorthogonalize_rotation();

    /**
     @brief returns a mutable reference to a matrix entry
     @param[in] r row of entry
     @param[in] c column of entry
     */
    float& operator()(int r, int c);

    /**
     @brief transforms a point by the current transformation
     and renormalizes the homogeneous coordinate to 1
     @param[in] pin pointer to input point [x,y,z,w]^T
     @param[out] pout pointer to output point [x,y,z,1]^T
     */
    void transform_homogeneous(float* pin, float* pout);

    /**
     @brief transforms a point by this transformation
     @param[in] pin pointer to input point [x,y,z]^T, homogeneous coordinate assumed to be 1
     @param[out] pout pointer to output point [x,y,z]^T, homogeneous coordinate set to be 1
     */
    void transform_point(float* pin, float* pout);

    /**
     @brief transforms a vector by this transformation
     @param[in] vin pointer to input vector [x,y,z], homogeneous coordinate assumed to be 0
     @param[out] vout pointer to output vector [x,y,z], homogeneous coordinate set to be 0
     */
    void transform_vector(float* vin, float* vout);

    /**
     @brief returns the transpose of the current transformation. Does not change this transform.
     */
    transformation transpose();

    /**
     @brief returns this transformation post-multiplied by the input transformation. Does not change this transform.
     @param[in] in transformation to multiply the current transform by
     */
    transformation operator*(transformation in);

    /**
     @brief returns the inverse of this transform. Does not change this transform.
     */
    transformation inverse();

    /**
     @brief returns a transformation with all elements zeroed
     */
    static transformation zero();

    /**
     @brief static member function to return an identity matrix. Effectively glLoadIdentity
     */
    static transformation identity();

    /**
     @brief static member function to return a scaling matrix
     @param[in] x scale factor for x-axis
     @param[in] y scale factor for y-axis
     @param[in] z scale factor for z-axis
     */
    static transformation scale(float x, float y, float z);

    /**
     @brief static member function to return a translation matrix
     @param[in] x offset for x-axis
     @param[in] y offset for y-axis
     @param[in] z offset for z-axis
     */
    static transformation translate(float x, float y, float z);

    /**
     @brief static member function to return a rotation about the x-axis
     @param[in] theta rotation angle in radians
     */
    static transformation rotate_x(float theta);

    /**
     @brief static member function to return a rotation about the y-axis
     @param[in] theta rotation angle in radians
     */
    static transformation rotate_y(float theta);

    /**
     @brief static member function to return a rotation about the z-axis
     @param[in] theta rotation angle in radians
     */
    static transformation rotate_z(float theta);

    /**
     @brief static member function to return a rotation about an arbitrary axis.
     @param[in] theta angle to rotate by, in RADIANS
     @param[in] x axis vector x component
     @param[in] y axis vector y component
     @param[in] z axis vector z component
     */
    static transformation rotate_axis(float theta, float x, float y, float z);

    /**
     @brief computes the closest rigid transformation between two corresponding
     point sets via singular-value decomposition. Requires Eigen.
     @param[in] npts number of points in pointsets
     @param[in] p0 packed array of points, i.e. [x0, y0, z0, x1, y1, z1, .... ]
     @param[in] p1 packed array of points
     @return rigid transformation which most closesly maps points in p0 to points in p1
    */
    static transformation best_rigid_transformation(int npts, float* p0, float* p1);

    /**
     @brief static member function to return an identity tranformation. Convenience
     definition that simply wraps transformation::identity()
     */
    static transformation glIdentity();

    /**
     @brief static member function to return a scaling matrix. Convenience definition
     that simply wraps transformation::scale()

     @param[in] x scale factor for x-axis
     @param[in] y scale factor for y-axis
     @param[in] z scale factor for z-axis
     */
    static transformation glScale(float x, float y, float z);

    /**
     @brief static member function to return a translation. Convenience definition
     that simply wraps transformation::translate()

     @param[in] x translation along x-axis
     @param[in] y translation along y-axis
     @param[in] z translation along z-axis
     */
    static transformation glTranslate(float x, float y, float z);

    /**
     @brief static member function to return a rotation about an arbitrary axis. Convenience
     definition that wraps transformation::rotate_axis(), but handles conversion from degrees
     to radians.

     @param[in] theta angle to rotate by, in DEGREES
     @param[in] x axis vector x component
     @param[in] y axis vector y component
     @param[in] z axis vector z component
     */
    static transformation glRotate(float theta, float x, float y, float z);

    /**
     @brief static member function to return a orthographic projeciton matrix
     identical to that produced by OpenGL's glOrtho() function

     @param[in] left left clipping plane position
     @param[in] right right clipping plane position
     @param[in] bottom bottom clipping plane position
     @param[in] top top clipping plane position
     @param[in] near near clipping plane position
     @param[in] far far clipping plane position
     */
    static transformation glOrtho(float left, float right, float bottom, float top, float nearVal, float farVal);

    /**
     @brief static member fuction to return a perspective projection matrix
     identical to that produced by OpenGL's glFrustum() function
     @param[in] left left clipping plane coordinate
     @param[in] right right clipping plane coordinate
     @param[in] bottom bottom clipping plane coordinate
     @param[in] top top clipping plane coordinate
     @param[in] nearVal near clipping plane distance, must be positive
     @param[in] farVal far clipping plane distance, must be positive
     */
    static transformation glFrustum(float left, float right, float bottom, float top, float nearVal, float farVal);

    /**
     @brief implementation of the glProject() function
     @param[in] objX x-coordinate of point on object
     @param[in] objY y-coordinate of point on object
     @param[in] objZ z-coordinate of point on object
     @param[in] model OpenGL formatted 'modelview' matrix
     @param[in] proj  OpenGL formatted projection matrix
     @param[in] view  OpenGL viewport [left, right, width, height]
     @param[out] winX output window x-coordinate
     @param[out] winY output window y-coordinate
     @param[out] winZ output window z-coordinate
     */
    static void gluProject(float objX, float objY, float objZ, float* model, float* proj, int* view, float* winx, float* winY, float* winZ);

    /**
     @brief implementation of the gluUnProject() function
     @param[in] winX output window x-coordinate
     @param[in] winY output window y-coordinate
     @param[in] winZ output window z-coordinate
     @param[in] model OpenGL formatted 'modelview' matrix
     @param[in] proj  OpenGL formatted projection matrix
     @param[in] view  OpenGL viewport [left, right, width, height]
     @param[out] objX x-coordinate of point on object
     @param[out] objY y-coordinate of point on object
     @param[out] objZ z-coordinate of point on object
     */
    static void gluUnProject(float winX, float winY, float winZ, float* model, float* proj, int* view, float* objX, float* objY, float* objZ);

    /**
     @brief constructs a transformation corresponding to an OpenGL modelview matrix
     which places the camera at [eyeX, eyeY, eyeZ]^T looking at [centerX, centerY, centerZ]^T
     with up vector [upX, upY, upZ]^T
     @param[in] eyeX eye position x-coordinate
     @param[in] eyeY eye position y-coordinate
     @param[in] eyeZ eye position z-coordinate
     @param[in] centerX viewed position x-coordinate
     @param[in] centerY viewed position y-coordinate
     @param[in] centerZ viewed position z-coordinate
     @param[in] upX up-vector x-coordinate
     @param[in] upY up-vector y-coordinate
     @param[in] upZ up-vector z-coordinate
     */
    static transformation gluLookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);

    /**
     @brief constructs the transformation corresponding to an OpenGL projection matrix
     generated by gluPerspective.
     @param[in] fovy field of view angle (degrees) in the y-direction
     @param[in] aspect aspect ratio, which determines the field of view angle in the x-direction
     @param[in] zNear near clip plane distance
     @param[in] zFar far clip plane distance
     */
    static transformation gluPerspective(float fovy, float aspect, float zNear, float zFar);
};

#endif
