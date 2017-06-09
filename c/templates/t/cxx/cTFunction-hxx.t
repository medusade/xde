%########################################################################
%# Copyright (c) 1988-2017 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: cTFunction-hxx.t
%#
%# Author: $author$
%#   Date: 5/31/2017
%########################################################################
%with(%
%name,%(%else-then(%name%,%(Name)%)%)%,%
%Name,%(%else-then(%Name%,%(%name%)%)%)%,%
%NAME,%(%else-then(%NAME%,%(%toupper(%Name%)%)%)%)%,%
%name,%(%else-then(%_Name%,%(%tolower(%Name%)%)%)%)%,%
%parameters,%(%else-then(%parameters%,%(Parameters)%)%)%,%
%Parameters,%(%else-then(%Parameters%,%(%parameters%)%)%)%,%
%PARAMETERS,%(%else-then(%PARAMETERS%,%(%toupper(%Parameters%)%)%)%)%,%
%parameters,%(%else-then(%_Parameters%,%(%tolower(%Parameters%)%)%)%)%,%
%description,%(%else-then(%description%,%(Description)%)%)%,%
%Description,%(%else-then(%Description%,%(%description%)%)%)%,%
%DESCRIPTION,%(%else-then(%DESCRIPTION%,%(%toupper(%Description%)%)%)%)%,%
%description,%(%else-then(%_Description%,%(%tolower(%Description%)%)%)%)%,%
%%(/**
 **********************************************************************
 *  Class: c%Name%TFunction
 *
 * Author: $author$
 *   Date: %date()%
 **********************************************************************
 */
class c%Name%TFunction: public cTFunction {
public:
   typedef cTFunction cExtends;

   /**
    **********************************************************************
    * Constructor: c%Name%TFunction
    *
    *      Author: $author$
    *        Date: %date()%
    **********************************************************************
    */
   c%Name%TFunction(const char* name, const char* description)
   : cExtends(name, description) {
       static cTFunctionParameter parameter[]
       = {/*{"%name%",""},
          {"(do)",""},*/
          {0,0}};
       m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
       m_parameter = parameter;
   }
   /**
    **********************************************************************
    * Function: Expand
    *
    *   Author: $author$
    *     Date: %date()%
    **********************************************************************
    */
   virtual eError Expand
   (cCharStreamInterface &result, cTInterface &t,
    const cTFunctionArgumentList& arglist) const {
       const char* chars = 0;
       TLENGTH count = 0;
       cString string;

       if ((chars) && (count)) {
           result.Write(chars, count);
       }
       return e_ERROR_NONE;
   }
} g_c%Name%TFunction
 ("%name%","%name%([%name%,(do)])");

)%)%