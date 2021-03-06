#ifndef _MMatrixArray
#define _MMatrixArray
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MMatrixArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MMatrixArray)
//
//  This class implements an array of Matrices.  Common convenience functions
//  are available, and the implementation is compatible with the internal
//  Maya implementation so that it can be passed efficiently between plugins
//  and internal maya data structures.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MTypes.h>
#include <maya/MStatus.h>
#include <maya/MMatrix.h>

// *****************************************************************************
// DECLARATIONS
// *****************************************************************************

// CLASS DECLARATION (MMatrixArray)

/// Array of MMatrix data type
/// Implements an array of MMatrix data type.

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MMatrixArray  
{

public:
	///
					MMatrixArray();
	///
					MMatrixArray( const MMatrixArray & other );
	///
					MMatrixArray( unsigned initialSize );
	///
					~MMatrixArray();
	///
 	const MMatrix&	operator[]( unsigned index ) const;
	///
 	MMatrix &		operator[]( unsigned index );
 	///
 	MMatrixArray &  operator=( const MMatrixArray & other );
	///
	MStatus			set( const MMatrix& element, unsigned index );
	///
	MStatus			setLength( unsigned length );
	///
	unsigned		length() const;
	///
	MStatus			remove( unsigned index );
	///
	MStatus			insert( const MMatrix & element, unsigned index );
	///
	MStatus			append( const MMatrix & element );
 	///
 	MStatus			copy( const MMatrixArray& source );
	///
	MStatus			clear();
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;
	///
	friend OPENMAYA_EXPORT IOS_REF(ostream) &operator<<(IOS_REF(ostream) &os,
									const MMatrixArray &array);

protected:
// No protected members

private:
	MMatrixArray( void* );
	void * arr;
	bool   own;
	static const char* className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MMatrixArray */
