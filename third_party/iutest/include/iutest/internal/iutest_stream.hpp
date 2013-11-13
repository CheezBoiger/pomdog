//======================================================================
//-----------------------------------------------------------------------
/**
 * @file		iutest_stream.hpp
 * @brief		iris unit test io stream �t�@�C��
 *
 * @author		t.sirayanagi
 * @version		1.0
 *
 * @par			copyright
 * Copyright (C) 2012-2013, Takazumi Shirayanagi\n
 * This software is released under the new BSD License,
 * see LICENSE
*/
//-----------------------------------------------------------------------
//======================================================================
#ifndef INCG_IRIS_iutest_stream_HPP_3A4AF139_9F24_4730_81D0_DADFCE6DCF99_
#define INCG_IRIS_iutest_stream_HPP_3A4AF139_9F24_4730_81D0_DADFCE6DCF99_

//======================================================================
// include

namespace iutest {
namespace detail
{

//======================================================================
// class
/**
 * @brief	�o�̓X�g���[���C���^�[�t�F�C�X
*/
class IOutStream
{
public:
	virtual ~IOutStream(void) {}
public:
	//! ��������
	virtual bool	Write(const void* buf, size_t size, size_t cnt) = 0;
public:
	virtual void	Printf(const char* fmt, ...)
	{
IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_BEGIN()

		// TODO : Fixed buffer...
		char buf[1024] = {0};
		va_list va;
		va_start(va, fmt);
#if defined(_MSC_VER)
#  if IUTEST_HAS_WANT_SECURE_LIB
		const int len = _vsnprintf_s(buf, _TRUNCATE, fmt, va);
#  else
		const int len = _vsnprintf(buf, sizeof(buf)-1, fmt, va);
#  endif
#else
#if defined(__STRICT_ANSI__)
		const int len = vsprintf(buf, fmt, va);
#else
		const int len = vsnprintf(buf, sizeof(buf), fmt, va);
#endif
#endif
		va_end(va);

		if( len > 0 )
			Write(buf, static_cast<size_t>(len), 1);

IUTEST_PRAGMA_CRT_SECURE_WARN_DISABLE_END()
	}
};

/**
 * @brief	�t�@�C��IO�o�̓X�g���[���C���^�[�t�F�C�X
*/
class FileOutStream : public IOutStream
{
protected:
	FILE*	m_fp;
public:
	FileOutStream(FILE* fp) IUTEST_CXX_NOEXCEPT_SPEC
		: m_fp(fp)
	{}
public:
	/**
	 * @brief	��������
	 * @param [in]	buf		= �������݃o�b�t�@
	 * @param [in]	size	= �o�b�t�@�T�C�Y
	 * @param [in]	cnt		= �������݉�
	*/
	virtual bool Write(const void* buf, size_t size, size_t cnt) IUTEST_CXX_OVERRIDE
	{
		if( fwrite(buf, size, cnt, m_fp) < cnt ) return false;
		return true;
	}
};

}	// end of namespace detail
}	// end of namespace iutest

#endif