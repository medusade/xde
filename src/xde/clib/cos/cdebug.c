/**
 **********************************************************************
 * Copyright (c) 1988-2007 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: cdebug.c
 *
 * Author: $author$
 *   Date: 11/13/2007
 *
 **********************************************************************
 */
#define DEBUG_EXPORT
#include "cdebug.h"
#undef DEBUG_EXPORT

#if defined(WIN32) 
/* Windows
 */
#else /* defined(WIN32) */
/* Unix
 */
#endif /* defined(WIN32) */

TDEBUG_LEVEL DEBUG_LEVELS = DEFAULT_DEBUG_LEVEL_VALUE;
