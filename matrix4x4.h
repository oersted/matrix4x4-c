/*
 * Copyright (c) 2009, Mozilla Corp
 * Copyright (c) 2012, Google, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY <copyright holder> ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Based on sample code from the OpenGL(R) ES 2.0 Programming Guide, which carriers
 * the following header:
 *
 * Book:      OpenGL(R) ES 2.0 Programming Guide
 * Authors:   Aaftab Munshi, Dan Ginsburg, Dave Shreiner
 * ISBN-10:   0321502795
 * ISBN-13:   9780321502797
 * Publisher: Addison-Wesley Professional
 * URLs:      http://safari.informit.com/9780321563835
 *            http://www.opengles-book.com
 */

/*
 * Ported from JavaScript to C by Behdad Esfahbod, 2012.
 * Added MultMatrix.  Converting from fixed-function OpenGL matrix
 * operations to these functions should be as simple as renaming the
 * 'gl' prefix to 'm4' and adding the matrix argument to the call.
 *
 * The C version lives at http://code.google.com/p/matrix4x4-c/
 */

/*
 * A simple 4x4 matrix utility implementation
 */

#ifndef MATRIX4x4_H
#define MATRIX4x4_H

#include <GL/gl.h>

/* Copies other matrix into mat */
GLdouble *
m4Copy (GLdouble *mat, const float *other);

GLdouble *
m4Multiply (GLdouble *mat, const float *right);

GLdouble *
m4MultMatrix (GLdouble *mat, const float *left);

inline GLdouble
m4Get (GLdouble *mat, unsigned int row, unsigned int col);

GLdouble *
m4Scale (GLdouble *mat, float sx, float sy, float sz);

GLdouble *
m4Translate (GLdouble *mat, float tx, float ty, float tz);

GLdouble *
m4Rotate (GLdouble *mat, float angle, float x, float y, float z);

GLdouble *
m4Frustum (GLdouble *mat, float left, float right, float bottom, float top, float nearZ, float farZ);

GLdouble *
m4Perspective (GLdouble *mat, float fovy, float aspect, float nearZ, float farZ);

GLdouble *
m4Ortho (GLdouble *mat, float left, float right, float bottom, float top, float nearZ, float farZ);

/* In-place inversion */
GLdouble *
m4Invert (GLdouble *mat);

/* Puts the inverse of other matrix into mat */
GLdouble *
m4Inverse (GLdouble *mat, const float *other);

/* In-place transpose */
GLdouble *
m4Transpose (GLdouble *mat);

GLdouble *
m4LoadIdentity (GLdouble *mat);

#endif
