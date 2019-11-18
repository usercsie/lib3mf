/*++

Copyright (C) 2019 3MF Consortium (Original Author)

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Abstract: This is a stub class definition of CVolumeData

*/

#include "lib3mf_volumedata.hpp"
#include "lib3mf_interfaceexception.hpp"

// Include custom headers here.
#include "lib3mf_volumedatalevelset.hpp"

using namespace Lib3MF::Impl;

/*************************************************************************************************************************
 Class definition of CVolumeData 
**************************************************************************************************************************/

CVolumeData::CVolumeData(NMR::PModelMeshObject pMeshObject, NMR::PModelVolumeData pVolumeData, NMR::CModel* pModel)
	: m_pVolumeData(pVolumeData), m_pMeshObject(pMeshObject), m_pModel(pModel)
{
	if (m_pVolumeData.get() == nullptr)
		throw ELib3MFInterfaceException(LIB3MF_ERROR_INVALIDPARAM);
}

IVolumeDataLevelset * CVolumeData::GetLevelset()
{
	if (m_pVolumeData->GetLevelset()) {
		return new CVolumeDataLevelset(m_pVolumeData->GetLevelset(), m_pModel);
	}
	return nullptr;
}

IVolumeDataLevelset * CVolumeData::CreateNewLevelset(IVolumetricStack* pTheVolumetricStack)
{
	NMR::PModelVolumetricStack pVolStack = m_pModel->findVolumetricStack(pTheVolumetricStack->GetResourceID());
	if (!pVolStack) {
		throw ELib3MFInterfaceException(LIB3MF_ERROR_RESOURCENOTFOUND);
	}
	return new CVolumeDataLevelset(m_pVolumeData->CreateLevelset(pVolStack), m_pModel);
}

IVolumeDataComposite * CVolumeData::GetComposite()
{
	throw ELib3MFInterfaceException(LIB3MF_ERROR_NOTIMPLEMENTED);
}

IVolumeDataComposite * CVolumeData::CreateNewComposite(IVolumetricStack* pTheVolumetricStack)
{
	throw ELib3MFInterfaceException(LIB3MF_ERROR_NOTIMPLEMENTED);
}

IVolumeDataColor * CVolumeData::GetColor()
{
	throw ELib3MFInterfaceException(LIB3MF_ERROR_NOTIMPLEMENTED);
}

IVolumeDataColor * CVolumeData::CreateNewColor(IVolumetricStack* pTheVolumetricStack)
{
	throw ELib3MFInterfaceException(LIB3MF_ERROR_NOTIMPLEMENTED);
}

Lib3MF_uint32 CVolumeData::GetPropertyCount()
{
	throw ELib3MFInterfaceException(LIB3MF_ERROR_NOTIMPLEMENTED);
}

IVolumeDataProperty * CVolumeData::GetProperty(const Lib3MF_uint32 nIndex)
{
	throw ELib3MFInterfaceException(LIB3MF_ERROR_NOTIMPLEMENTED);
}

IVolumeDataProperty * CVolumeData::AddProperty(IVolumetricStack* pTheVolumetricStack)
{
	throw ELib3MFInterfaceException(LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CVolumeData::RemoveProperty(const Lib3MF_uint32 nIndex)
{
	throw ELib3MFInterfaceException(LIB3MF_ERROR_NOTIMPLEMENTED);
}
