/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         admstpathparse
#define yylex           admstpathlex
#define yyerror         admstpatherror
#define yydebug         admstpathdebug
#define yynerrs         admstpathnerrs
#define yylval          admstpathlval
#define yychar          admstpathchar

/* First part of user prologue.  */
#line 8 "admstpathYacc.y"

#include "admstpathYacc.h"

static int admstpathlex (p_pparse mypparse);
static void dbpath (p_path mypath);
static void dbtext (p_text mytext);
static void postpath (p_path mypath);
static void posttext (p_text mytext)
{
  p_slist li;
  for(li=mytext->_token;li;li=li->next)
  {
    p_adms mytoken=li->data;
    if(mytoken->_datatypename==admse_path)
    {
      ((p_path)mytoken)->_aname=adms_kclone("//");
      adms_k2strconcat(&((p_path)mytoken)->_aname,mytext->_aname);
      postpath((p_path)mytoken);
    }
    else if(mytoken->_datatypename==admse_text)
    {
      ((p_text)mytoken)->_aname=adms_kclone("//");
      adms_k2strconcat(&((p_text)mytoken)->_aname,mytext->_aname);
      posttext((p_text)mytoken);
    }
  }
}
void dbxx (const p_transform mytransform)
{
  if(!is_admst(mytransform->_name))
  {
    p_slist l=mytransform->_attribute;
    for(;l;l=l->next)
      dbtext((p_text)((p_attribute)l->data)->_value);
  }
  if(!strcmp(mytransform->_name,"admst")&&mytransform->_textversion) dbtext(mytransform->_textversion);
  if(!strcmp(mytransform->_name,"admst:for-each")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:for-each")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:for-each")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:join")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:join")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:join")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:join")&&mytransform->_textseparator) dbtext(mytransform->_textseparator);
  if(!strcmp(mytransform->_name,"admst:break")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:break")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:value-of")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:value-of")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:value-of")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:if-inside")&&mytransform->_textlist) dbtext(mytransform->_textlist);
  if(!strcmp(mytransform->_name,"admst:if-inside")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:if-inside")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:if-inside")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:if-not-inside")&&mytransform->_textlist) dbtext(mytransform->_textlist);
  if(!strcmp(mytransform->_name,"admst:if-not-inside")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:if-not-inside")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:if-not-inside")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:choose")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:choose")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:when")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:when")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:otherwise")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:otherwise")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:if")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:if")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:template")&&mytransform->_textmatch) dbtext(mytransform->_textmatch);
  if(!strcmp(mytransform->_name,"admst:template")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:template")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:apply-templates")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:apply-templates")&&mytransform->_textmatch) dbtext(mytransform->_textmatch);
  if(!strcmp(mytransform->_name,"admst:apply-templates")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:apply-templates")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:apply-templates")&&mytransform->_textrequired) dbtext(mytransform->_textrequired);
  if(!strcmp(mytransform->_name,"admst:return")&&mytransform->_textname) dbtext(mytransform->_textname);
  if(!strcmp(mytransform->_name,"admst:return")&&mytransform->_textstring) dbtext(mytransform->_textstring);
  if(!strcmp(mytransform->_name,"admst:return")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:return")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:attribute")&&mytransform->_textname) dbtext(mytransform->_textname);
  if(!strcmp(mytransform->_name,"admst:attribute")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:attribute")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:attribute")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:variable")&&mytransform->_textname) dbtext(mytransform->_textname);
  if(!strcmp(mytransform->_name,"admst:variable")&&mytransform->_textstring) dbtext(mytransform->_textstring);
  if(!strcmp(mytransform->_name,"admst:variable")&&mytransform->_textselect) dbtext(mytransform->_textselect);
  if(!strcmp(mytransform->_name,"admst:variable")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:variable")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:value-to")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:value-to")&&mytransform->_textstring) dbtext(mytransform->_textstring);
  if(!strcmp(mytransform->_name,"admst:value-to")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:value-to")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:text")&&mytransform->_textformat) dbtext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:text")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:text")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:text")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:new")&&mytransform->_textdatatype) dbtext(mytransform->_textdatatype);
  if(!strcmp(mytransform->_name,"admst:new")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:new")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:new")&&mytransform->_textarguments)
  {
    p_slist l=mytransform->_textarguments;
    for(;l;l=l->next)
      dbtext((p_text)l->data);
  }
  if(!strcmp(mytransform->_name,"admst:new")&&mytransform->_pathinputs)
  {
    p_slist l=mytransform->_pathinputs;
    for(;l;l=l->next)
      dbpath((p_path)l->data);
  }
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_pathinto) dbpath(mytransform->_pathinto);
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_textonduplicate) dbtext(mytransform->_textonduplicate);
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_pathoncompare) dbpath(mytransform->_pathoncompare);
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:reset")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:reset")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:reset")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:count")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:count")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:count")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:reverse")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:reverse")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:reverse")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:read")&&mytransform->_textfile) dbtext(mytransform->_textfile);
  if(!strcmp(mytransform->_name,"admst:read")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:read")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:open")&&mytransform->_textfile) dbtext(mytransform->_textfile);
  if(!strcmp(mytransform->_name,"admst:open")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:open")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:setenv")&&mytransform->_textname) dbtext(mytransform->_textname);
  if(!strcmp(mytransform->_name,"admst:setenv")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:setenv")&&mytransform->_textstring) dbtext(mytransform->_textstring);
  if(!strcmp(mytransform->_name,"admst:setenv")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:getenv")&&mytransform->_textname) dbtext(mytransform->_textname);
  if(!strcmp(mytransform->_name,"admst:getenv")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:getenv")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:copy")&&mytransform->_textfrom) dbtext(mytransform->_textfrom);
  if(!strcmp(mytransform->_name,"admst:copy")&&mytransform->_textto) dbtext(mytransform->_textto);
  if(!strcmp(mytransform->_name,"admst:copy")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:copy")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:assert")&&mytransform->_textformat) dbtext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:assert")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:assert")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:assert")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:message")&&mytransform->_textformat) dbtext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:message")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:message")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:message")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:warning")&&mytransform->_textformat) dbtext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:warning")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:warning")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:warning")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:error")&&mytransform->_textformat) dbtext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:error")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:error")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:error")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:fatal")&&mytransform->_textformat) dbtext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:fatal")&&mytransform->_pathpath) dbpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:fatal")&&mytransform->_pathtest) dbpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:fatal")&&mytransform->_pathselect) dbpath(mytransform->_pathselect);
}
void postxx (p_transform mytransform)
{
  if(!is_admst(mytransform->_name))
  {
    p_slist l=mytransform->_attribute;
    for(;l;l=l->next)
      posttext((p_text)((p_attribute)l->data)->_value);
  }
  if(!strcmp(mytransform->_name,"admst")&&mytransform->_textversion) posttext(mytransform->_textversion);
  if(!strcmp(mytransform->_name,"admst:for-each")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:for-each")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:for-each")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:join")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:join")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:join")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:join")&&mytransform->_textseparator) posttext(mytransform->_textseparator);
  if(!strcmp(mytransform->_name,"admst:break")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:break")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:value-of")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:value-of")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:value-of")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:if-inside")&&mytransform->_textlist) posttext(mytransform->_textlist);
  if(!strcmp(mytransform->_name,"admst:if-inside")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:if-inside")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:if-inside")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:if-not-inside")&&mytransform->_textlist) posttext(mytransform->_textlist);
  if(!strcmp(mytransform->_name,"admst:if-not-inside")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:if-not-inside")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:if-not-inside")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:choose")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:choose")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:when")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:when")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:otherwise")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:otherwise")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:if")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:if")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:template")&&mytransform->_textmatch) posttext(mytransform->_textmatch);
  if(!strcmp(mytransform->_name,"admst:template")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:template")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:apply-templates")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:apply-templates")&&mytransform->_textmatch) posttext(mytransform->_textmatch);
  if(!strcmp(mytransform->_name,"admst:apply-templates")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:apply-templates")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:apply-templates")&&mytransform->_textrequired) posttext(mytransform->_textrequired);
  if(!strcmp(mytransform->_name,"admst:return")&&mytransform->_textname) posttext(mytransform->_textname);
  if(!strcmp(mytransform->_name,"admst:return")&&mytransform->_textstring) posttext(mytransform->_textstring);
  if(!strcmp(mytransform->_name,"admst:return")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:return")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:attribute")&&mytransform->_textname) posttext(mytransform->_textname);
  if(!strcmp(mytransform->_name,"admst:attribute")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:attribute")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:attribute")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:variable")&&mytransform->_textname) posttext(mytransform->_textname);
  if(!strcmp(mytransform->_name,"admst:variable")&&mytransform->_textstring) posttext(mytransform->_textstring);
  if(!strcmp(mytransform->_name,"admst:variable")&&mytransform->_textselect) posttext(mytransform->_textselect);
  if(!strcmp(mytransform->_name,"admst:variable")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:variable")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:value-to")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:value-to")&&mytransform->_textstring) posttext(mytransform->_textstring);
  if(!strcmp(mytransform->_name,"admst:value-to")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:value-to")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:text")&&mytransform->_textformat) posttext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:text")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:text")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:text")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:new")&&mytransform->_textdatatype) posttext(mytransform->_textdatatype);
  if(!strcmp(mytransform->_name,"admst:new")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:new")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:new")&&mytransform->_textarguments)
  {
    p_slist l=mytransform->_textarguments;
    for(;l;l=l->next)
      posttext((p_text)l->data);
  }
  if(!strcmp(mytransform->_name,"admst:new")&&mytransform->_pathinputs)
  {
    p_slist l=mytransform->_pathinputs;
    for(;l;l=l->next)
      postpath((p_path)l->data);
  }
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_pathinto) postpath(mytransform->_pathinto);
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_textonduplicate) posttext(mytransform->_textonduplicate);
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_pathoncompare) postpath(mytransform->_pathoncompare);
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:push")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:reset")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:reset")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:reset")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:count")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:count")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:count")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:reverse")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:reverse")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:reverse")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:read")&&mytransform->_textfile) posttext(mytransform->_textfile);
  if(!strcmp(mytransform->_name,"admst:read")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:read")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:open")&&mytransform->_textfile) posttext(mytransform->_textfile);
  if(!strcmp(mytransform->_name,"admst:open")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:open")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:setenv")&&mytransform->_textname) posttext(mytransform->_textname);
  if(!strcmp(mytransform->_name,"admst:setenv")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:setenv")&&mytransform->_textstring) posttext(mytransform->_textstring);
  if(!strcmp(mytransform->_name,"admst:setenv")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:getenv")&&mytransform->_textname) posttext(mytransform->_textname);
  if(!strcmp(mytransform->_name,"admst:getenv")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:getenv")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:copy")&&mytransform->_textfrom) posttext(mytransform->_textfrom);
  if(!strcmp(mytransform->_name,"admst:copy")&&mytransform->_textto) posttext(mytransform->_textto);
  if(!strcmp(mytransform->_name,"admst:copy")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:copy")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:assert")&&mytransform->_textformat) posttext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:assert")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:assert")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:assert")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:message")&&mytransform->_textformat) posttext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:message")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:message")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:message")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:warning")&&mytransform->_textformat) posttext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:warning")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:warning")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:warning")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:error")&&mytransform->_textformat) posttext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:error")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:error")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:error")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
  if(!strcmp(mytransform->_name,"admst:fatal")&&mytransform->_textformat) posttext(mytransform->_textformat);
  if(!strcmp(mytransform->_name,"admst:fatal")&&mytransform->_pathpath) postpath(mytransform->_pathpath);
  if(!strcmp(mytransform->_name,"admst:fatal")&&mytransform->_pathtest) postpath(mytransform->_pathtest);
  if(!strcmp(mytransform->_name,"admst:fatal")&&mytransform->_pathselect) postpath(mytransform->_pathselect);
}
void sanityxx (p_transform mytransform)
{
  if(!is_admst(mytransform->_name)) { }
  else if(!strcmp(mytransform->_name,"admst"))
  {
  }
  else if(!strcmp(mytransform->_name,"admst:for-each"))
  {
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathtest) adms_message_fatal(("transform does not support attribute 'test' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:join"))
  {
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathtest) adms_message_fatal(("transform does not support attribute 'test' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:break"))
  {
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:value-of"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:if-inside"))
  {
    if(!mytransform->_children) adms_message_fatal(("transform requires children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textlist) adms_message_fatal(("transform requires attribute 'list' - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:if-not-inside"))
  {
    if(!mytransform->_children) adms_message_fatal(("transform requires children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textlist) adms_message_fatal(("transform requires attribute 'list' - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:choice")||!strcmp(mytransform->_name,"admst:choose"))
  {
    if(!strcmp(mytransform->_name,"admst:choice")) adms_message_obsolete(("%s: please use 'admst:choose' instead\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathtest) adms_message_fatal(("transform does not support attribute 'test' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:when"))
  {
    if(!mytransform->_pathtest) adms_message_fatal(("transform requires attribute 'test' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:otherwise"))
  {
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathtest) adms_message_fatal(("transform does not support attribute 'test' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:if"))
  {
    if(!mytransform->_children) adms_message_fatal(("transform requires children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_pathtest) adms_message_fatal(("transform requires attribute 'test' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:templates")||!strcmp(mytransform->_name,"admst:template"))
  {
    if(!strcmp(mytransform->_name,"admst:templates")) adms_message_obsolete(("%s: please use 'admst:template' instead\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textmatch) adms_message_fatal(("transform requires attribute 'match' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:apply-template")||!strcmp(mytransform->_name,"admst:apply-templates"))
  {
    if(!strcmp(mytransform->_name,"admst:apply-template")) adms_message_obsolete(("%s: please use 'admst:apply-templates' instead\n",adms_transform_uid(mytransform)))
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textmatch) adms_message_fatal(("transform requires attribute 'match' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:return"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textname) adms_message_fatal(("transform requires attribute 'name' - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textstring) adms_message_fatal(("transform requires attribute 'string' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:attribute"))
  {
    if(!mytransform->_children) adms_message_fatal(("transform requires children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textname) adms_message_fatal(("transform requires attribute 'name' - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:variable"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textname) adms_message_fatal(("transform requires attribute 'name' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:value-to"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:text"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:new"))
  {
    if(!mytransform->_textdatatype) adms_message_fatal(("transform requires attribute 'datatype' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:push"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_pathinto) adms_message_fatal(("transform requires attribute 'into' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:reset"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:count"))
  {
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:reverse"))
  {
    if(!mytransform->_pathselect) adms_message_fatal(("transform requires attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:read"))
  {
    if(!mytransform->_textfile) adms_message_fatal(("transform requires attribute 'file' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:open"))
  {
    if(!mytransform->_textfile) adms_message_fatal(("transform requires attribute 'file' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:setenv"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textname) adms_message_fatal(("transform requires attribute 'name' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:getenv"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textname) adms_message_fatal(("transform requires attribute 'name' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:copy"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textfrom) adms_message_fatal(("transform requires attribute 'from' - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textto) adms_message_fatal(("transform requires attribute 'to' - see %s\n",adms_transform_uid(mytransform)))
    if(mytransform->_pathselect) adms_message_fatal(("transform does not support attribute 'select' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:assert"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_pathtest) adms_message_fatal(("transform requires attribute 'test' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:message"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textformat) adms_message_fatal(("transform requires attribute 'format' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:warning"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textformat) adms_message_fatal(("transform requires attribute 'format' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:error"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textformat) adms_message_fatal(("transform requires attribute 'format' - see %s\n",adms_transform_uid(mytransform)))
  }
  else if(!strcmp(mytransform->_name,"admst:fatal"))
  {
    if(mytransform->_children) adms_message_fatal(("transform does not support children - see %s\n",adms_transform_uid(mytransform)))
    if(!mytransform->_textformat) adms_message_fatal(("transform requires attribute 'format' - see %s\n",adms_transform_uid(mytransform)))
  }
  else adms_message_fatal(("%s: unknown transform\n",adms_transform_uid(mytransform)))
}
static void location030adms(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_list)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_discipline)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nodealias)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branchalias)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_analog)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_string)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_subexpression)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_unary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variable)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_array)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instanceparameter)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instancenode)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nilled)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_case)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_caseitem)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_blockvariable)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_callfunction)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_evaluation)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_attribute)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_lexval)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'adms' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030math(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_string)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_subexpression)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_unary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variable)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_array)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instanceparameter)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instancenode)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nilled)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_case)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_caseitem)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_blockvariable)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_callfunction)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'math' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030subexpression(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_mapply_unary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variable)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_array)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'subexpression' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030usedininitial_step(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedininitial_step);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedininitial_step;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedininitial_step); d->_valueto=(void*)adms_variableprototype_valueto_usedininitial_step;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedininitial_step' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030curfilename(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_admsmain)ai->_item.p)->_curfilename); d->_valueto=(void*)adms_admsmain_valueto_curfilename;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'curfilename' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030lexval(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_lexval);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_lexval;
  }
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_analogfunction)(ai->_item.p))->_lexval); d->_valueto=(void*)adms_analogfunction_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)(ai->_item.p))->_lexval); d->_valueto=(void*)adms_variableprototype_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_number)(ai->_item.p))->_lexval); d->_valueto=(void*)adms_number_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_function)(ai->_item.p))->_lexval); d->_valueto=(void*)adms_function_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_assignment)(ai->_item.p))->_lexval); d->_valueto=(void*)adms_assignment_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_contribution)(ai->_item.p))->_lexval); d->_valueto=(void*)adms_contribution_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_block)(ai->_item.p))->_lexval); d->_valueto=(void*)adms_block_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'lexval' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030units(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nature)ai->_item.p)->_units); d->_valueto=(void*)adms_nature_valueto_units;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'units' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030tmp1(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_tmp1); d->_valueto=(void*)adms_simulator_valueto_tmp1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'tmp1' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030abstol(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nature)(ai->_item.p))->_abstol); d->_valueto=(void*)adms_nature_valueto_abstol;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'abstol' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030vcount(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbi(d0,ai,((p_variableprototype)d0->_item.p)->_vcount);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_vcount;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_variableprototype)ai->_item.p)->_vcount); d->_valueto=(void*)adms_variableprototype_valueto_vcount;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'vcount' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030instance(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_instance;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_variableprototype)
  {
    p_slist lii=((p_variableprototype)ai->_item.p)->_instance;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'instance' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030branch(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_branch;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_branchalias)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branchalias)(ai->_item.p))->_branch); d->_valueto=(void*)adms_branchalias_valueto_branch;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_source)(ai->_item.p))->_branch); d->_valueto=(void*)adms_source_valueto_branch;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_probe)(ai->_item.p))->_branch); d->_valueto=(void*)adms_probe_valueto_branch;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'branch' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030datatype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_list)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_list)ai->_item.p)->_datatype); d->_valueto=(void*)adms_list_valueto_datatype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'datatype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030package_tarname(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_package_tarname); d->_valueto=(void*)adms_simulator_valueto_package_tarname;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'package_tarname' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030fullfilename(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_admsmain)ai->_item.p)->_fullfilename); d->_valueto=(void*)adms_admsmain_valueto_fullfilename;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'fullfilename' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030vlast(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_vlast);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_vlast;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)(ai->_item.p))->_vlast); d->_valueto=(void*)adms_variableprototype_valueto_vlast;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'vlast' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030forloop(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_forloop;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'forloop' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030ddt_nature(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nature)(ai->_item.p))->_ddt_nature); d->_valueto=(void*)adms_nature_valueto_ddt_nature;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'ddt_nature' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030rhs(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_assignment)(ai->_item.p))->_rhs); d->_valueto=(void*)adms_assignment_valueto_rhs;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_contribution)(ai->_item.p))->_rhs); d->_valueto=(void*)adms_contribution_valueto_rhs;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'rhs' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030setinnoise(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setinnoise);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setinnoise;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setinnoise); d->_valueto=(void*)adms_variableprototype_valueto_setinnoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setinnoise' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030error(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_error); d->_valueto=(void*)adms_admsmain_valueto_error;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'error' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030nodefrominstantiator(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_instancenode)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instancenode)(ai->_item.p))->_nodefrominstantiator); d->_valueto=(void*)adms_instancenode_valueto_nodefrominstantiator;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'nodefrominstantiator' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030flow(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_discipline)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_discipline)(ai->_item.p))->_flow); d->_valueto=(void*)adms_discipline_valueto_flow;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'flow' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030while(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_whileloop)(ai->_item.p))->_while); d->_valueto=(void*)adms_whileloop_valueto_while;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'while' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030scalingunit(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_number)ai->_item.p)->_scalingunit); d->_valueto=(void*)adms_number_valueto_scalingunit;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'scalingunit' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030node(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_node;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_nodealias)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nodealias)(ai->_item.p))->_node); d->_valueto=(void*)adms_nodealias_valueto_node;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'node' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030OPdependent(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_OPdependent);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_OPdependent;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_OPdependent); d->_valueto=(void*)adms_variableprototype_valueto_OPdependent;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'OPdependent' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030seen(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_probe)ai->_item.p)->_seen); d->_valueto=(void*)adms_probe_valueto_seen;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'seen' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030usedininstance(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedininstance);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedininstance;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedininstance); d->_valueto=(void*)adms_variableprototype_valueto_usedininstance;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedininstance' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030br2(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_simulator)(ai->_item.p))->_br2); d->_valueto=(void*)adms_simulator_valueto_br2;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'br2' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030fullname(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_fullname); d->_valueto=(void*)adms_simulator_valueto_fullname;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'fullname' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030module(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_module);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_module;
  }
  else if(e==admse_admsmain)
  {
    p_slist lii=((p_admsmain)ai->_item.p)->_module;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_analogfunction)(ai->_item.p))->_module); d->_valueto=(void*)adms_analogfunction_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nodealias)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nodealias)(ai->_item.p))->_module); d->_valueto=(void*)adms_nodealias_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_node)(ai->_item.p))->_module); d->_valueto=(void*)adms_node_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branchalias)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branchalias)(ai->_item.p))->_module); d->_valueto=(void*)adms_branchalias_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branch)(ai->_item.p))->_module); d->_valueto=(void*)adms_branch_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)(ai->_item.p))->_module); d->_valueto=(void*)adms_variableprototype_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_source)(ai->_item.p))->_module); d->_valueto=(void*)adms_source_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_range)(ai->_item.p))->_module); d->_valueto=(void*)adms_range_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_jacobian)(ai->_item.p))->_module); d->_valueto=(void*)adms_jacobian_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_probe)(ai->_item.p))->_module); d->_valueto=(void*)adms_probe_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_expression)(ai->_item.p))->_module); d->_valueto=(void*)adms_expression_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instance)(ai->_item.p))->_module); d->_valueto=(void*)adms_instance_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nilled)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nilled)(ai->_item.p))->_module); d->_valueto=(void*)adms_nilled_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_assignment)(ai->_item.p))->_module); d->_valueto=(void*)adms_assignment_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_contribution)(ai->_item.p))->_module); d->_valueto=(void*)adms_contribution_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_conditional)(ai->_item.p))->_module); d->_valueto=(void*)adms_conditional_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_forloop)(ai->_item.p))->_module); d->_valueto=(void*)adms_forloop_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_whileloop)(ai->_item.p))->_module); d->_valueto=(void*)adms_whileloop_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_case)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_case)(ai->_item.p))->_module); d->_valueto=(void*)adms_case_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_block)(ai->_item.p))->_module); d->_valueto=(void*)adms_block_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_callfunction)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_callfunction)(ai->_item.p))->_module); d->_valueto=(void*)adms_callfunction_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'module' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030filename(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_admsmain)ai->_item.p)->_filename); d->_valueto=(void*)adms_admsmain_valueto_filename;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'filename' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030simulator(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_admsmain)(ai->_item.p))->_simulator); d->_valueto=(void*)adms_admsmain_valueto_simulator;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'simulator' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030flickernoise(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_flickernoise); d->_valueto=(void*)adms_source_valueto_flickernoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_contribution)ai->_item.p)->_flickernoise); d->_valueto=(void*)adms_contribution_valueto_flickernoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'flickernoise' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030forblock(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_forloop)(ai->_item.p))->_forblock); d->_valueto=(void*)adms_forloop_valueto_forblock;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'forblock' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030supboundtype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_range)ai->_item.p)->_supboundtype); d->_valueto=(void*)adms_range_valueto_supboundtype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'supboundtype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030dbg_xml(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_dbg_xml); d->_valueto=(void*)adms_admsmain_valueto_dbg_xml;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'dbg_xml' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030discipline(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_slist lii=((p_admsmain)ai->_item.p)->_discipline;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_node)(ai->_item.p))->_discipline); d->_valueto=(void*)adms_node_valueto_discipline;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branch)(ai->_item.p))->_discipline); d->_valueto=(void*)adms_branch_valueto_discipline;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_source)(ai->_item.p))->_discipline); d->_valueto=(void*)adms_source_valueto_discipline;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_probe)(ai->_item.p))->_discipline); d->_valueto=(void*)adms_probe_valueto_discipline;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'discipline' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030usedinnoise(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedinnoise);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedinnoise;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedinnoise); d->_valueto=(void*)adms_variableprototype_valueto_usedinnoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedinnoise' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030terminal(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_instance)
  {
    p_slist lii=((p_instance)ai->_item.p)->_terminal;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'terminal' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030condition(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_forloop)(ai->_item.p))->_condition); d->_valueto=(void*)adms_forloop_valueto_condition;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_caseitem)
  {
    p_slist lii=((p_caseitem)ai->_item.p)->_condition;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'condition' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030expression(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_expression;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_subexpression)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_subexpression)(ai->_item.p))->_expression); d->_valueto=(void*)adms_subexpression_valueto_expression;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'expression' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030grounded(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_node)ai->_item.p)->_grounded); d->_valueto=(void*)adms_node_valueto_grounded;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_branch)ai->_item.p)->_grounded); d->_valueto=(void*)adms_branch_valueto_grounded;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_grounded); d->_valueto=(void*)adms_source_valueto_grounded;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_probe)ai->_item.p)->_grounded); d->_valueto=(void*)adms_probe_valueto_grounded;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'grounded' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030hint(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_hint); d->_valueto=(void*)adms_admsmain_valueto_hint;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'hint' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030switch(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_switch); d->_valueto=(void*)adms_source_valueto_switch;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'switch' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030cast(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_number)ai->_item.p)->_cast); d->_valueto=(void*)adms_number_valueto_cast;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'cast' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030range(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA0*/ p_slist l1=((p_variableprototype)d0->_item.p)->_range;
    for(;l1;l1=l1->next)
    {
      p_admst d1=adms_admst_newpa(d0,ai,l1->data);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;
    }
  }
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_range;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_variableprototype)
  {
    p_slist lii=((p_variableprototype)ai->_item.p)->_range;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'range' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030package_bugreport(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_package_bugreport); d->_valueto=(void*)adms_simulator_valueto_package_bugreport;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'package_bugreport' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030dynamic(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  else if(e==admse_expression)
    e=admse_math;
  else if(e==admse_nilled)
    e=admse_math;
  else if(e==admse_assignment)
    e=admse_math;
  else if(e==admse_contribution)
    e=admse_math;
  else if(e==admse_conditional)
    e=admse_math;
  else if(e==admse_forloop)
    e=admse_math;
  else if(e==admse_whileloop)
    e=admse_math;
  else if(e==admse_case)
    e=admse_math;
  else if(e==admse_blockvariable)
    e=admse_math;
  else if(e==admse_block)
    e=admse_math;
  else if(e==admse_callfunction)
    e=admse_math;
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_dynamic);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_dynamic;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_dynamic); d->_valueto=(void*)adms_variableprototype_valueto_dynamic;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_dynamic); d->_valueto=(void*)adms_source_valueto_dynamic;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_jacobian)ai->_item.p)->_dynamic); d->_valueto=(void*)adms_jacobian_valueto_dynamic;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_math)ai->_item.p)->_dynamic); d->_valueto=(void*)adms_math_valueto_dynamic;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'dynamic' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030setinmodel(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setinmodel);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setinmodel;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setinmodel); d->_valueto=(void*)adms_variableprototype_valueto_setinmodel;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setinmodel' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030arraydefault(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variableprototype)
  {
    p_slist lii=((p_variableprototype)ai->_item.p)->_arraydefault;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'arraydefault' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030jacobian(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_jacobian;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'jacobian' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030itransform(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_slist lii=((p_admsmain)ai->_item.p)->_itransform;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'itransform' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030case(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_case;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_case)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_case)(ai->_item.p))->_case); d->_valueto=(void*)adms_case_valueto_case;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'case' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030ddxprobe(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA0*/ p_slist l1=((p_variableprototype)d0->_item.p)->_ddxprobe;
    for(;l1;l1=l1->next)
    {
      p_admst d1=adms_admst_newpa(d0,ai,l1->data);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;
    }
  }
  else if(e==admse_variableprototype)
  {
    p_slist lii=((p_variableprototype)ai->_item.p)->_ddxprobe;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'ddxprobe' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030obsolete(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_obsolete); d->_valueto=(void*)adms_admsmain_valueto_obsolete;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'obsolete' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030ddx(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_ddx); d->_valueto=(void*)adms_simulator_valueto_ddx;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'ddx' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030ddt_name(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nature)ai->_item.p)->_ddt_name); d->_valueto=(void*)adms_nature_valueto_ddt_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'ddt_name' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030arg3(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_ternary)(ai->_item.p))->_arg3); d->_valueto=(void*)adms_mapply_ternary_valueto_arg3;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'arg3' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030c(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_lexval)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_lexval)ai->_item.p)->_c); d->_valueto=(void*)adms_lexval_valueto_c;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'c' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030debug(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_debug); d->_valueto=(void*)adms_admsmain_valueto_debug;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'debug' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030arg2(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_binary)(ai->_item.p))->_arg2); d->_valueto=(void*)adms_mapply_binary_valueto_arg2;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_ternary)(ai->_item.p))->_arg2); d->_valueto=(void*)adms_mapply_ternary_valueto_arg2;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'arg2' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030else(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_conditional)(ai->_item.p))->_else); d->_valueto=(void*)adms_conditional_valueto_else;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'else' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030parameterset(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_instance)
  {
    p_slist lii=((p_instance)ai->_item.p)->_parameterset;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'parameterset' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030index(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_array)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_array)(ai->_item.p))->_index); d->_valueto=(void*)adms_array_valueto_index;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'index' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030block(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_block);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_block;
  }
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_block;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)(ai->_item.p))->_block); d->_valueto=(void*)adms_variableprototype_valueto_block;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_blockvariable)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_blockvariable)(ai->_item.p))->_block); d->_valueto=(void*)adms_blockvariable_valueto_block;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_block)(ai->_item.p))->_block); d->_valueto=(void*)adms_block_valueto_block;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'block' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030derivate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_derivate);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_derivate;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_derivate); d->_valueto=(void*)adms_variableprototype_valueto_derivate;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'derivate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030function(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_expression)
  {
    p_slist lii=((p_expression)ai->_item.p)->_function;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_callfunction)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_callfunction)(ai->_item.p))->_function); d->_valueto=(void*)adms_callfunction_valueto_function;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'function' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030nnode(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branch)(ai->_item.p))->_nnode); d->_valueto=(void*)adms_branch_valueto_nnode;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'nnode' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030supexpr(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_range)(ai->_item.p))->_supexpr); d->_valueto=(void*)adms_range_valueto_supexpr;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'supexpr' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030usedinevaluate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedinevaluate);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedinevaluate;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedinevaluate); d->_valueto=(void*)adms_variableprototype_valueto_usedinevaluate;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedinevaluate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030itransforminsideapplytemplate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_slist lii=((p_admsmain)ai->_item.p)->_itransforminsideapplytemplate;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'itransforminsideapplytemplate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030infinity(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_expression)ai->_item.p)->_infinity); d->_valueto=(void*)adms_expression_valueto_infinity;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'infinity' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030infexpr(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_range)(ai->_item.p))->_infexpr); d->_valueto=(void*)adms_range_valueto_infexpr;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'infexpr' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030potential(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_discipline)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_discipline)(ai->_item.p))->_potential); d->_valueto=(void*)adms_discipline_valueto_potential;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'potential' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030defaultcase(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_caseitem)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_caseitem)ai->_item.p)->_defaultcase); d->_valueto=(void*)adms_caseitem_valueto_defaultcase;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'defaultcase' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030value(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_number)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_number)ai->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_number_valueto_lexval;
    /*BBBB0*/ p_admst d1=adms_admst_newbs(d0,ai,((p_lexval)d0->_item.p)->_string);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newbr(ai,ai,((p_math)ai->_item.p)->_value); d->_valueto=(void*)adms_math_valueto_value;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_string)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_string)ai->_item.p)->_value); d->_valueto=(void*)adms_string_valueto_value;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_expression)ai->_item.p)->_value); d->_valueto=(void*)adms_expression_valueto_value;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instanceparameter)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instanceparameter)(ai->_item.p))->_value); d->_valueto=(void*)adms_instanceparameter_valueto_value;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_return)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_return)ai->_item.p)->_value); d->_valueto=(void*)adms_return_valueto_value;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_attribute)
  {
    p_admst d=adms_admst_newpc(ai,ai,(p_attribute)ai->_item.p);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'value' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030tree(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_analogfunction)(ai->_item.p))->_tree); d->_valueto=(void*)adms_analogfunction_valueto_tree;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_expression)(ai->_item.p))->_tree); d->_valueto=(void*)adms_expression_valueto_tree;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'tree' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030instantiator(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_instantiator;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instance)(ai->_item.p))->_instantiator); d->_valueto=(void*)adms_instance_valueto_instantiator;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'instantiator' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030usage(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_usage); d->_valueto=(void*)adms_admsmain_valueto_usage;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usage' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030update(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_forloop)(ai->_item.p))->_update); d->_valueto=(void*)adms_forloop_valueto_update;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'update' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030dependency(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  else if(e==admse_string)
    e=admse_math;
  else if(e==admse_subexpression)
    e=admse_math;
  else if(e==admse_mapply_unary)
    e=admse_math;
  else if(e==admse_mapply_binary)
    e=admse_math;
  else if(e==admse_mapply_ternary)
    e=admse_math;
  else if(e==admse_number)
    e=admse_math;
  else if(e==admse_function)
    e=admse_math;
  else if(e==admse_variable)
    e=admse_math;
  else if(e==admse_array)
    e=admse_math;
  else if(e==admse_probe)
    e=admse_math;
  else if(e==admse_expression)
    e=admse_math;
  else if(e==admse_instance)
    e=admse_math;
  else if(e==admse_instanceparameter)
    e=admse_math;
  else if(e==admse_instancenode)
    e=admse_math;
  else if(e==admse_nilled)
    e=admse_math;
  else if(e==admse_assignment)
    e=admse_math;
  else if(e==admse_contribution)
    e=admse_math;
  else if(e==admse_conditional)
    e=admse_math;
  else if(e==admse_forloop)
    e=admse_math;
  else if(e==admse_whileloop)
    e=admse_math;
  else if(e==admse_case)
    e=admse_math;
  else if(e==admse_caseitem)
    e=admse_math;
  else if(e==admse_blockvariable)
    e=admse_math;
  else if(e==admse_block)
    e=admse_math;
  else if(e==admse_callfunction)
    e=admse_math;
  if(0) {}
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_dependency); d->_valueto=(void*)adms_variableprototype_valueto_dependency;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_math)ai->_item.p)->_dependency); d->_valueto=(void*)adms_math_valueto_dependency;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'dependency' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030whileloop(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_whileloop;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'whileloop' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030blockvariable(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_blockvariable;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'blockvariable' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030then(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_conditional)(ai->_item.p))->_then); d->_valueto=(void*)adms_conditional_valueto_then;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'then' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030analog(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_module)(ai->_item.p))->_analog); d->_valueto=(void*)adms_module_valueto_analog;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'analog' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030nodefrommodule(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_instancenode)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instancenode)(ai->_item.p))->_nodefrommodule); d->_valueto=(void*)adms_instancenode_valueto_nodefrommodule;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'nodefrommodule' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030whileblock(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_whileloop)(ai->_item.p))->_whileblock); d->_valueto=(void*)adms_whileloop_valueto_whileblock;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'whileblock' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030usedinfinal(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedinfinal);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedinfinal;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedinfinal); d->_valueto=(void*)adms_variableprototype_valueto_usedinfinal;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedinfinal' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030default(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_default);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_default;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)(ai->_item.p))->_default); d->_valueto=(void*)adms_variableprototype_valueto_default;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'default' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030evaluation(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_module)(ai->_item.p))->_evaluation); d->_valueto=(void*)adms_module_valueto_evaluation;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'evaluation' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030sizetype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_sizetype);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_sizetype;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_sizetype); d->_valueto=(void*)adms_variableprototype_valueto_sizetype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'sizetype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030unique_id(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_function)ai->_item.p)->_unique_id); d->_valueto=(void*)adms_function_valueto_unique_id;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'unique_id' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030setinfinal(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setinfinal);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setinfinal;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setinfinal); d->_valueto=(void*)adms_variableprototype_valueto_setinfinal;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setinfinal' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030dbg_vla(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_dbg_vla); d->_valueto=(void*)adms_admsmain_valueto_dbg_vla;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'dbg_vla' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030type(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_type);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_type;
  }
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_analogfunction)ai->_item.p)->_type); d->_valueto=(void*)adms_analogfunction_valueto_type;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_type); d->_valueto=(void*)adms_variableprototype_valueto_type;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_type); d->_valueto=(void*)adms_source_valueto_type;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_range)ai->_item.p)->_type); d->_valueto=(void*)adms_range_valueto_type;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'type' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030currentdate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_currentdate); d->_valueto=(void*)adms_simulator_valueto_currentdate;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'currentdate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030if(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_conditional)(ai->_item.p))->_if); d->_valueto=(void*)adms_conditional_valueto_if;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'if' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030setininitial_step(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setininitial_step);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setininitial_step;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setininitial_step); d->_valueto=(void*)adms_variableprototype_valueto_setininitial_step;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setininitial_step' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030parameter(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_instanceparameter)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instanceparameter)(ai->_item.p))->_parameter); d->_valueto=(void*)adms_instanceparameter_valueto_parameter;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'parameter' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030invtransform(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_slist lii=((p_admsmain)ai->_item.p)->_invtransform;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'invtransform' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030lhs(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_assignment)(ai->_item.p))->_lhs); d->_valueto=(void*)adms_assignment_valueto_lhs;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_contribution)(ai->_item.p))->_lhs); d->_valueto=(void*)adms_contribution_valueto_lhs;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'lhs' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030TemperatureDependent(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_TemperatureDependent);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_TemperatureDependent;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_TemperatureDependent); d->_valueto=(void*)adms_variableprototype_valueto_TemperatureDependent;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_expression)ai->_item.p)->_TemperatureDependent); d->_valueto=(void*)adms_expression_valueto_TemperatureDependent;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'TemperatureDependent' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030scope(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_scope);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_scope;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_scope); d->_valueto=(void*)adms_variableprototype_valueto_scope;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'scope' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030column(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_jacobian)(ai->_item.p))->_column); d->_valueto=(void*)adms_jacobian_valueto_column;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'column' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030warning(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_warning); d->_valueto=(void*)adms_admsmain_valueto_warning;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'warning' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030caseitem(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_case)
  {
    p_slist lii=((p_case)ai->_item.p)->_caseitem;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'caseitem' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030valueof(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_slist lii=((p_admsmain)ai->_item.p)->_valueof;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'valueof' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030string(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_lexval)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_lexval)ai->_item.p)->_string); d->_valueto=(void*)adms_lexval_valueto_string;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'string' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030fpos(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_admsmain)ai->_item.p)->_fpos); d->_valueto=(void*)adms_admsmain_valueto_fpos;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'fpos' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030setingetprev(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setingetprev);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setingetprev;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setingetprev); d->_valueto=(void*)adms_variableprototype_valueto_setingetprev;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setingetprev' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030nature(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_slist lii=((p_admsmain)ai->_item.p)->_nature;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_source)(ai->_item.p))->_nature); d->_valueto=(void*)adms_source_valueto_nature;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_probe)(ai->_item.p))->_nature); d->_valueto=(void*)adms_probe_valueto_nature;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'nature' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030verbose(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_verbose); d->_valueto=(void*)adms_admsmain_valueto_verbose;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'verbose' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030callfunction(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_callfunction;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'callfunction' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030conditional(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_conditional;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'conditional' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030maxsize(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_maxsize);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_maxsize;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)(ai->_item.p))->_maxsize); d->_valueto=(void*)adms_variableprototype_valueto_maxsize;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'maxsize' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030argc(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_admsmain)ai->_item.p)->_argc); d->_valueto=(void*)adms_admsmain_valueto_argc;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'argc' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030setininstance(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setininstance);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setininstance;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setininstance); d->_valueto=(void*)adms_variableprototype_valueto_setininstance;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setininstance' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030idt_nature(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nature)(ai->_item.p))->_idt_nature); d->_valueto=(void*)adms_nature_valueto_idt_nature;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'idt_nature' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030arguments(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_function)
  {
    p_slist lii=((p_function)ai->_item.p)->_arguments;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'arguments' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030definition(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_function)(ai->_item.p))->_definition); d->_valueto=(void*)adms_function_valueto_definition;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'definition' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030input(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_input);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_input;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_input); d->_valueto=(void*)adms_variableprototype_valueto_input;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'input' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030probe(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA0*/ p_slist l1=((p_variableprototype)d0->_item.p)->_probe;
    for(;l1;l1=l1->next)
    {
      p_admst d1=adms_admst_newpa(d0,ai,l1->data);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;
    }
  }
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_simulator)(ai->_item.p))->_probe); d->_valueto=(void*)adms_simulator_valueto_probe;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_probe;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_variableprototype)
  {
    p_slist lii=((p_variableprototype)ai->_item.p)->_probe;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_source)
  {
    p_slist lii=((p_source)ai->_item.p)->_probe;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_expression)
  {
    p_slist lii=((p_expression)ai->_item.p)->_probe;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_block)
  {
    p_slist lii=((p_block)ai->_item.p)->_probe;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'probe' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030arg1(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_mapply_unary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_unary)(ai->_item.p))->_arg1); d->_valueto=(void*)adms_mapply_unary_valueto_arg1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_binary)(ai->_item.p))->_arg1); d->_valueto=(void*)adms_mapply_binary_valueto_arg1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_ternary)(ai->_item.p))->_arg1); d->_valueto=(void*)adms_mapply_ternary_valueto_arg1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'arg1' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030idt_name(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nature)ai->_item.p)->_idt_name); d->_valueto=(void*)adms_nature_valueto_idt_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'idt_name' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030usedinmodel(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedinmodel);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedinmodel;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedinmodel); d->_valueto=(void*)adms_variableprototype_valueto_usedinmodel;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedinmodel' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030infboundtype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_range)ai->_item.p)->_infboundtype); d->_valueto=(void*)adms_range_valueto_infboundtype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'infboundtype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030base(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nature)(ai->_item.p))->_base); d->_valueto=(void*)adms_nature_valueto_base;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'base' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030location(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_node)ai->_item.p)->_location); d->_valueto=(void*)adms_node_valueto_location;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'location' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030contribution(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_contribution;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'contribution' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030row(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_jacobian)(ai->_item.p))->_row); d->_valueto=(void*)adms_jacobian_valueto_row;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'row' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030f(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_lexval)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_lexval)ai->_item.p)->_f); d->_valueto=(void*)adms_lexval_valueto_f;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'f' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030l(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_lexval)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_lexval)ai->_item.p)->_l); d->_valueto=(void*)adms_lexval_valueto_l;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'l' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030sr1(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_simulator)(ai->_item.p))->_sr1); d->_valueto=(void*)adms_simulator_valueto_sr1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'sr1' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030package_string(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_package_string); d->_valueto=(void*)adms_simulator_valueto_package_string;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'package_string' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030package_name(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_package_name); d->_valueto=(void*)adms_simulator_valueto_package_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'package_name' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030static(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  else if(e==admse_expression)
    e=admse_math;
  else if(e==admse_nilled)
    e=admse_math;
  else if(e==admse_assignment)
    e=admse_math;
  else if(e==admse_contribution)
    e=admse_math;
  else if(e==admse_conditional)
    e=admse_math;
  else if(e==admse_forloop)
    e=admse_math;
  else if(e==admse_whileloop)
    e=admse_math;
  else if(e==admse_case)
    e=admse_math;
  else if(e==admse_blockvariable)
    e=admse_math;
  else if(e==admse_block)
    e=admse_math;
  else if(e==admse_callfunction)
    e=admse_math;
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_static);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_static;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_static); d->_valueto=(void*)adms_variableprototype_valueto_static;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_static); d->_valueto=(void*)adms_source_valueto_static;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_jacobian)ai->_item.p)->_static); d->_valueto=(void*)adms_jacobian_valueto_static;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_math)ai->_item.p)->_static); d->_valueto=(void*)adms_math_valueto_static;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'static' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030diagonal(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_jacobian)ai->_item.p)->_diagonal); d->_valueto=(void*)adms_jacobian_valueto_diagonal;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'diagonal' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030pnode(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branch)(ai->_item.p))->_pnode); d->_valueto=(void*)adms_branch_valueto_pnode;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'pnode' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030alias(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA0*/ p_slist l1=((p_variableprototype)d0->_item.p)->_alias;
    for(;l1;l1=l1->next)
    {
      p_admst d1=adms_admst_newpa(d0,ai,l1->data);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;
    }
  }
  else if(e==admse_variableprototype)
  {
    p_slist lii=((p_variableprototype)ai->_item.p)->_alias;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newbs(ai,ai,(char*)lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'alias' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030whitenoise(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_whitenoise); d->_valueto=(void*)adms_source_valueto_whitenoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_contribution)ai->_item.p)->_whitenoise); d->_valueto=(void*)adms_contribution_valueto_whitenoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'whitenoise' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030assignment(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA0*/ p_slist l1=((p_variableprototype)d0->_item.p)->_assignment;
    for(;l1;l1=l1->next)
    {
      p_admst d1=adms_admst_newpa(d0,ai,l1->data);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;
    }
  }
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_assignment;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_variableprototype)
  {
    p_slist lii=((p_variableprototype)ai->_item.p)->_assignment;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'assignment' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030package_version(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_package_version); d->_valueto=(void*)adms_simulator_valueto_package_version;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'package_version' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030developer(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_developer); d->_valueto=(void*)adms_simulator_valueto_developer;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'developer' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030br1(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_simulator)(ai->_item.p))->_br1); d->_valueto=(void*)adms_simulator_valueto_br1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'br1' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030hasspecialnumber(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_expression)ai->_item.p)->_hasspecialnumber); d->_valueto=(void*)adms_expression_valueto_hasspecialnumber;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'hasspecialnumber' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030prototype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variable)(ai->_item.p))->_prototype); d->_valueto=(void*)adms_variable_valueto_prototype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'prototype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030class(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_function)ai->_item.p)->_class); d->_valueto=(void*)adms_function_valueto_class;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'class' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030analogfunction(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_analogfunction;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'analogfunction' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030dbg_mem(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_dbg_mem); d->_valueto=(void*)adms_admsmain_valueto_dbg_mem;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'dbg_mem' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030minsize(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_minsize);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_minsize;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)(ai->_item.p))->_minsize); d->_valueto=(void*)adms_variableprototype_valueto_minsize;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'minsize' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030argv(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_slist lii=((p_admsmain)ai->_item.p)->_argv;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newbs(ai,ai,(char*)lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'argv' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030tmp(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_tmp); d->_valueto=(void*)adms_simulator_valueto_tmp;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'tmp' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030transform(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_slist lii=((p_admsmain)ai->_item.p)->_transform;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'transform' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030code(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_analog)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_analog)(ai->_item.p))->_code); d->_valueto=(void*)adms_analog_valueto_code;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_caseitem)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_caseitem)(ai->_item.p))->_code); d->_valueto=(void*)adms_caseitem_valueto_code;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'code' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030isstate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_isstate);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_isstate;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_isstate); d->_valueto=(void*)adms_variableprototype_valueto_isstate;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'isstate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030attribute(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA0*/ p_slist l1=((p_variableprototype)d0->_item.p)->_attribute;
    for(;l1;l1=l1->next)
    {
      p_admst d1=adms_admst_newpa(d0,ai,l1->data);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;
    }
  }
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_attribute;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_analogfunction)
  {
    p_slist lii=((p_analogfunction)ai->_item.p)->_attribute;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_node)
  {
    p_slist lii=((p_node)ai->_item.p)->_attribute;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_branch)
  {
    p_slist lii=((p_branch)ai->_item.p)->_attribute;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_variableprototype)
  {
    p_slist lii=((p_variableprototype)ai->_item.p)->_attribute;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_source)
  {
    p_slist lii=((p_source)ai->_item.p)->_attribute;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_math)
  {
    p_slist lii=((p_math)ai->_item.p)->_attribute;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_assignment)
  {
    p_slist lii=((p_assignment)ai->_item.p)->_attribute;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_contribution)
  {
    p_slist lii=((p_contribution)ai->_item.p)->_attribute;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_block)
  {
    p_slist lii=((p_block)ai->_item.p)->_attribute;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'attribute' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030output(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_output);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_output;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_output); d->_valueto=(void*)adms_variableprototype_valueto_output;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'output' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030source(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_source;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_probe)(ai->_item.p))->_source); d->_valueto=(void*)adms_probe_valueto_source;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'source' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030info(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_info); d->_valueto=(void*)adms_admsmain_valueto_info;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'info' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030item(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_list)
  {
    p_slist lii=((p_list)ai->_item.p)->_item;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpn(dot,dot,(p_admst)lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_block)
  {
    p_slist lii=((p_block)ai->_item.p)->_item;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'item' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030access(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nature)ai->_item.p)->_access); d->_valueto=(void*)adms_nature_valueto_access;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'access' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030direction(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_node)ai->_item.p)->_direction); d->_valueto=(void*)adms_node_valueto_direction;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'direction' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030domain(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_discipline)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_discipline)ai->_item.p)->_domain); d->_valueto=(void*)adms_discipline_valueto_domain;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'domain' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030nodealias(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_nodealias;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'nodealias' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030insource(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_insource);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_insource;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_insource); d->_valueto=(void*)adms_variableprototype_valueto_insource;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'insource' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030hasVoltageDependentFunction(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_expression)ai->_item.p)->_hasVoltageDependentFunction); d->_valueto=(void*)adms_expression_valueto_hasVoltageDependentFunction;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'hasVoltageDependentFunction' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030setinevaluate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setinevaluate);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setinevaluate;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setinevaluate); d->_valueto=(void*)adms_variableprototype_valueto_setinevaluate;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setinevaluate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030parametertype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_parametertype);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_parametertype;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_parametertype); d->_valueto=(void*)adms_variableprototype_valueto_parametertype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'parametertype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030name(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_analogfunction)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_analogfunction)ai->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_analogfunction_valueto_lexval;
    /*BBBB0*/ p_admst d1=adms_admst_newbs(d0,ai,((p_lexval)d0->_item.p)->_string);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_variableprototype)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)ai->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variableprototype_valueto_lexval;
    /*BBBB0*/ p_admst d1=adms_admst_newbs(d0,ai,((p_lexval)d0->_item.p)->_string);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_function)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_function)ai->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_function_valueto_lexval;
    /*BBBB0*/ p_admst d1=adms_admst_newbs(d0,ai,((p_lexval)d0->_item.p)->_string);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB0*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d1); d1->_valueto=(void*)adms_variableprototype_valueto_lexval;
    /*BBBB0*/ p_admst d2=adms_admst_newbs(d1,ai,((p_lexval)d1->_item.p)->_string);if(d2->_preva) d2->_preva->_nexta=d2->_nexta,d2->_preva=NULL; if(d2->_nexta) d2->_nexta->_preva=d2->_preva,d2->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d2; else p->_an->_nexta=d2,d2->_preva=p->_an,p->_an=d2;d2->_position=++p->_position;d2->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_block)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_block)ai->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_block_valueto_lexval;
    /*BBBB0*/ p_admst d1=adms_admst_newbs(d0,ai,((p_lexval)d0->_item.p)->_string);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_name); d->_valueto=(void*)adms_simulator_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_admsmain)ai->_item.p)->_name); d->_valueto=(void*)adms_admsmain_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nature)ai->_item.p)->_name); d->_valueto=(void*)adms_nature_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_discipline)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_discipline)ai->_item.p)->_name); d->_valueto=(void*)adms_discipline_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_module)ai->_item.p)->_name); d->_valueto=(void*)adms_module_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nodealias)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nodealias)ai->_item.p)->_name); d->_valueto=(void*)adms_nodealias_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_node)ai->_item.p)->_name); d->_valueto=(void*)adms_node_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branchalias)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_branchalias)ai->_item.p)->_name); d->_valueto=(void*)adms_branchalias_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_range)ai->_item.p)->_name); d->_valueto=(void*)adms_range_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_math)ai->_item.p)->_name); d->_valueto=(void*)adms_math_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_unary)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_mapply_unary)ai->_item.p)->_name); d->_valueto=(void*)adms_mapply_unary_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_mapply_binary)ai->_item.p)->_name); d->_valueto=(void*)adms_mapply_binary_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_mapply_ternary)ai->_item.p)->_name); d->_valueto=(void*)adms_mapply_ternary_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_instance)ai->_item.p)->_name); d->_valueto=(void*)adms_instance_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nilled)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nilled)ai->_item.p)->_name); d->_valueto=(void*)adms_nilled_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_assignment)ai->_item.p)->_name); d->_valueto=(void*)adms_assignment_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_contribution)ai->_item.p)->_name); d->_valueto=(void*)adms_contribution_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_conditional)ai->_item.p)->_name); d->_valueto=(void*)adms_conditional_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_forloop)ai->_item.p)->_name); d->_valueto=(void*)adms_forloop_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_whileloop)ai->_item.p)->_name); d->_valueto=(void*)adms_whileloop_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_case)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_case)ai->_item.p)->_name); d->_valueto=(void*)adms_case_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_return)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_return)ai->_item.p)->_name); d->_valueto=(void*)adms_return_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_attribute)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_attribute)ai->_item.p)->_name); d->_valueto=(void*)adms_attribute_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'name' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030curline(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_admsmain)ai->_item.p)->_curline); d->_valueto=(void*)adms_admsmain_valueto_curline;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'curline' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030variable(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB0*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA0*/ p_slist l1=((p_variableprototype)d0->_item.p)->_variable;
    for(;l1;l1=l1->next)
    {
      p_admst d1=adms_admst_newpa(d0,ai,l1->data);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;
    }
  }
  else if(e==admse_admsmain)
  {
    p_slist lii=((p_admsmain)ai->_item.p)->_variable;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_variable;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_analogfunction)
  {
    p_slist lii=((p_analogfunction)ai->_item.p)->_variable;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_variableprototype)
  {
    p_slist lii=((p_variableprototype)ai->_item.p)->_variable;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_array)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_array)(ai->_item.p))->_variable); d->_valueto=(void*)adms_array_valueto_variable;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_slist lii=((p_expression)ai->_item.p)->_variable;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_blockvariable)
  {
    p_slist lii=((p_blockvariable)ai->_item.p)->_variable;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_block)
  {
    p_slist lii=((p_block)ai->_item.p)->_variable;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_evaluation)
  {
    p_slist lii=((p_evaluation)ai->_item.p)->_variable;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'variable' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030branchalias(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_slist lii=((p_module)ai->_item.p)->_branchalias;
    for(;lii;lii=lii->next)
    {
      p_admst d=adms_admst_newpa(ai,ai,lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_contribution)(ai->_item.p))->_branchalias); d->_valueto=(void*)adms_contribution_valueto_branchalias;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'branchalias' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030fatal(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_fatal); d->_valueto=(void*)adms_admsmain_valueto_fatal;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'fatal' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location030initial(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_forloop)(ai->_item.p))->_initial); d->_valueto=(void*)adms_forloop_valueto_initial;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'initial' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}

static void location031adms(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_list)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_discipline)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nodealias)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branchalias)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_analog)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_string)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_subexpression)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_unary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variable)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_array)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instanceparameter)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instancenode)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nilled)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_case)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_caseitem)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_blockvariable)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_callfunction)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_evaluation)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_attribute)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_lexval)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_adms); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'adms' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031math(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_string)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_subexpression)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_unary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variable)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_array)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instanceparameter)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instancenode)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nilled)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_case)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_caseitem)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_blockvariable)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_callfunction)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_math); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'math' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031subexpression(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_mapply_unary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variable)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_array)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpp(ai,ai,admse_subexpression); d->_valueto=(void*)NULL;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'subexpression' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031usedininitial_step(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedininitial_step);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedininitial_step;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedininitial_step); d->_valueto=(void*)adms_variableprototype_valueto_usedininitial_step;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedininitial_step' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031curfilename(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_admsmain)ai->_item.p)->_curfilename); d->_valueto=(void*)adms_admsmain_valueto_curfilename;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'curfilename' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031lexval(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_lexval);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_lexval;
  }
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_analogfunction)ai->_item.p)->_lexval); d->_valueto=(void*)adms_analogfunction_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)ai->_item.p)->_lexval); d->_valueto=(void*)adms_variableprototype_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_number)ai->_item.p)->_lexval); d->_valueto=(void*)adms_number_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_function)ai->_item.p)->_lexval); d->_valueto=(void*)adms_function_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_assignment)ai->_item.p)->_lexval); d->_valueto=(void*)adms_assignment_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_contribution)ai->_item.p)->_lexval); d->_valueto=(void*)adms_contribution_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_block)ai->_item.p)->_lexval); d->_valueto=(void*)adms_block_valueto_lexval;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'lexval' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031units(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nature)ai->_item.p)->_units); d->_valueto=(void*)adms_nature_valueto_units;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'units' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031tmp1(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_tmp1); d->_valueto=(void*)adms_simulator_valueto_tmp1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'tmp1' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031abstol(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nature)ai->_item.p)->_abstol); d->_valueto=(void*)adms_nature_valueto_abstol;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'abstol' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031vcount(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbi(d0,ai,((p_variableprototype)d0->_item.p)->_vcount);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_vcount;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_variableprototype)ai->_item.p)->_vcount); d->_valueto=(void*)adms_variableprototype_valueto_vcount;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'vcount' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031instance(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_instance)); d->_valueto=(void*)adms_module_valueto_instance;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_variableprototype)ai->_item.p)->_instance)); d->_valueto=(void*)adms_variableprototype_valueto_instance;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'instance' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031branch(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_branch)); d->_valueto=(void*)adms_module_valueto_branch;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branchalias)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branchalias)ai->_item.p)->_branch); d->_valueto=(void*)adms_branchalias_valueto_branch;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_source)ai->_item.p)->_branch); d->_valueto=(void*)adms_source_valueto_branch;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_probe)ai->_item.p)->_branch); d->_valueto=(void*)adms_probe_valueto_branch;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'branch' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031datatype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_list)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_list)ai->_item.p)->_datatype); d->_valueto=(void*)adms_list_valueto_datatype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'datatype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031package_tarname(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_package_tarname); d->_valueto=(void*)adms_simulator_valueto_package_tarname;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'package_tarname' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031fullfilename(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_admsmain)ai->_item.p)->_fullfilename); d->_valueto=(void*)adms_admsmain_valueto_fullfilename;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'fullfilename' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031vlast(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_vlast);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_vlast;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)ai->_item.p)->_vlast); d->_valueto=(void*)adms_variableprototype_valueto_vlast;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'vlast' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031forloop(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_forloop)); d->_valueto=(void*)adms_module_valueto_forloop;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'forloop' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031ddt_nature(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nature)ai->_item.p)->_ddt_nature); d->_valueto=(void*)adms_nature_valueto_ddt_nature;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'ddt_nature' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031rhs(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_assignment)ai->_item.p)->_rhs); d->_valueto=(void*)adms_assignment_valueto_rhs;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_contribution)ai->_item.p)->_rhs); d->_valueto=(void*)adms_contribution_valueto_rhs;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'rhs' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031setinnoise(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setinnoise);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setinnoise;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setinnoise); d->_valueto=(void*)adms_variableprototype_valueto_setinnoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setinnoise' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031error(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_error); d->_valueto=(void*)adms_admsmain_valueto_error;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'error' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031nodefrominstantiator(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_instancenode)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instancenode)ai->_item.p)->_nodefrominstantiator); d->_valueto=(void*)adms_instancenode_valueto_nodefrominstantiator;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'nodefrominstantiator' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031flow(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_discipline)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_discipline)ai->_item.p)->_flow); d->_valueto=(void*)adms_discipline_valueto_flow;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'flow' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031while(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_whileloop)ai->_item.p)->_while); d->_valueto=(void*)adms_whileloop_valueto_while;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'while' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031scalingunit(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_number)ai->_item.p)->_scalingunit); d->_valueto=(void*)adms_number_valueto_scalingunit;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'scalingunit' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031node(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_node)); d->_valueto=(void*)adms_module_valueto_node;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nodealias)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nodealias)ai->_item.p)->_node); d->_valueto=(void*)adms_nodealias_valueto_node;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'node' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031OPdependent(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_OPdependent);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_OPdependent;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_OPdependent); d->_valueto=(void*)adms_variableprototype_valueto_OPdependent;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'OPdependent' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031seen(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_probe)ai->_item.p)->_seen); d->_valueto=(void*)adms_probe_valueto_seen;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'seen' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031usedininstance(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedininstance);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedininstance;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedininstance); d->_valueto=(void*)adms_variableprototype_valueto_usedininstance;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedininstance' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031br2(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_simulator)ai->_item.p)->_br2); d->_valueto=(void*)adms_simulator_valueto_br2;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'br2' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031fullname(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_fullname); d->_valueto=(void*)adms_simulator_valueto_fullname;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'fullname' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031module(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_module);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_module;
  }
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_admsmain)ai->_item.p)->_module)); d->_valueto=(void*)adms_admsmain_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_analogfunction)ai->_item.p)->_module); d->_valueto=(void*)adms_analogfunction_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nodealias)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nodealias)ai->_item.p)->_module); d->_valueto=(void*)adms_nodealias_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_node)ai->_item.p)->_module); d->_valueto=(void*)adms_node_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branchalias)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branchalias)ai->_item.p)->_module); d->_valueto=(void*)adms_branchalias_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branch)ai->_item.p)->_module); d->_valueto=(void*)adms_branch_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)ai->_item.p)->_module); d->_valueto=(void*)adms_variableprototype_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_source)ai->_item.p)->_module); d->_valueto=(void*)adms_source_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_range)ai->_item.p)->_module); d->_valueto=(void*)adms_range_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_jacobian)ai->_item.p)->_module); d->_valueto=(void*)adms_jacobian_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_probe)ai->_item.p)->_module); d->_valueto=(void*)adms_probe_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_expression)ai->_item.p)->_module); d->_valueto=(void*)adms_expression_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instance)ai->_item.p)->_module); d->_valueto=(void*)adms_instance_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nilled)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nilled)ai->_item.p)->_module); d->_valueto=(void*)adms_nilled_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_assignment)ai->_item.p)->_module); d->_valueto=(void*)adms_assignment_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_contribution)ai->_item.p)->_module); d->_valueto=(void*)adms_contribution_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_conditional)ai->_item.p)->_module); d->_valueto=(void*)adms_conditional_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_forloop)ai->_item.p)->_module); d->_valueto=(void*)adms_forloop_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_whileloop)ai->_item.p)->_module); d->_valueto=(void*)adms_whileloop_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_case)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_case)ai->_item.p)->_module); d->_valueto=(void*)adms_case_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_block)ai->_item.p)->_module); d->_valueto=(void*)adms_block_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_callfunction)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_callfunction)ai->_item.p)->_module); d->_valueto=(void*)adms_callfunction_valueto_module;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'module' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031filename(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_admsmain)ai->_item.p)->_filename); d->_valueto=(void*)adms_admsmain_valueto_filename;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'filename' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031simulator(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_admsmain)ai->_item.p)->_simulator); d->_valueto=(void*)adms_admsmain_valueto_simulator;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'simulator' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031flickernoise(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_flickernoise); d->_valueto=(void*)adms_source_valueto_flickernoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_contribution)ai->_item.p)->_flickernoise); d->_valueto=(void*)adms_contribution_valueto_flickernoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'flickernoise' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031forblock(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_forloop)ai->_item.p)->_forblock); d->_valueto=(void*)adms_forloop_valueto_forblock;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'forblock' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031supboundtype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_range)ai->_item.p)->_supboundtype); d->_valueto=(void*)adms_range_valueto_supboundtype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'supboundtype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031dbg_xml(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_dbg_xml); d->_valueto=(void*)adms_admsmain_valueto_dbg_xml;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'dbg_xml' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031discipline(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_admsmain)ai->_item.p)->_discipline)); d->_valueto=(void*)adms_admsmain_valueto_discipline;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_node)ai->_item.p)->_discipline); d->_valueto=(void*)adms_node_valueto_discipline;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branch)ai->_item.p)->_discipline); d->_valueto=(void*)adms_branch_valueto_discipline;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_source)ai->_item.p)->_discipline); d->_valueto=(void*)adms_source_valueto_discipline;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_probe)ai->_item.p)->_discipline); d->_valueto=(void*)adms_probe_valueto_discipline;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'discipline' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031usedinnoise(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedinnoise);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedinnoise;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedinnoise); d->_valueto=(void*)adms_variableprototype_valueto_usedinnoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedinnoise' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031terminal(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_instance)ai->_item.p)->_terminal)); d->_valueto=(void*)adms_instance_valueto_terminal;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'terminal' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031condition(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_forloop)ai->_item.p)->_condition); d->_valueto=(void*)adms_forloop_valueto_condition;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_caseitem)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_caseitem)ai->_item.p)->_condition)); d->_valueto=(void*)adms_caseitem_valueto_condition;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'condition' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031expression(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_expression)); d->_valueto=(void*)adms_module_valueto_expression;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_subexpression)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_subexpression)ai->_item.p)->_expression); d->_valueto=(void*)adms_subexpression_valueto_expression;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'expression' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031grounded(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_node)ai->_item.p)->_grounded); d->_valueto=(void*)adms_node_valueto_grounded;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_branch)ai->_item.p)->_grounded); d->_valueto=(void*)adms_branch_valueto_grounded;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_grounded); d->_valueto=(void*)adms_source_valueto_grounded;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_probe)ai->_item.p)->_grounded); d->_valueto=(void*)adms_probe_valueto_grounded;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'grounded' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031hint(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_hint); d->_valueto=(void*)adms_admsmain_valueto_hint;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'hint' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031switch(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_switch); d->_valueto=(void*)adms_source_valueto_switch;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'switch' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031cast(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_number)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_number)ai->_item.p)->_cast); d->_valueto=(void*)adms_number_valueto_cast;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'cast' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031range(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA1*/ p_admst d1=adms_admst_newla(d0,ai,((p_variableprototype)d0->_item.p)->_range);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_range;
  }
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_range)); d->_valueto=(void*)adms_module_valueto_range;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_variableprototype)ai->_item.p)->_range)); d->_valueto=(void*)adms_variableprototype_valueto_range;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'range' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031package_bugreport(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_package_bugreport); d->_valueto=(void*)adms_simulator_valueto_package_bugreport;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'package_bugreport' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031dynamic(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  else if(e==admse_expression)
    e=admse_math;
  else if(e==admse_nilled)
    e=admse_math;
  else if(e==admse_assignment)
    e=admse_math;
  else if(e==admse_contribution)
    e=admse_math;
  else if(e==admse_conditional)
    e=admse_math;
  else if(e==admse_forloop)
    e=admse_math;
  else if(e==admse_whileloop)
    e=admse_math;
  else if(e==admse_case)
    e=admse_math;
  else if(e==admse_blockvariable)
    e=admse_math;
  else if(e==admse_block)
    e=admse_math;
  else if(e==admse_callfunction)
    e=admse_math;
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_dynamic);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_dynamic;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_dynamic); d->_valueto=(void*)adms_variableprototype_valueto_dynamic;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_dynamic); d->_valueto=(void*)adms_source_valueto_dynamic;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_jacobian)ai->_item.p)->_dynamic); d->_valueto=(void*)adms_jacobian_valueto_dynamic;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_math)ai->_item.p)->_dynamic); d->_valueto=(void*)adms_math_valueto_dynamic;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'dynamic' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031setinmodel(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setinmodel);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setinmodel;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setinmodel); d->_valueto=(void*)adms_variableprototype_valueto_setinmodel;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setinmodel' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031arraydefault(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_variableprototype)ai->_item.p)->_arraydefault)); d->_valueto=(void*)adms_variableprototype_valueto_arraydefault;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'arraydefault' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031jacobian(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_jacobian)); d->_valueto=(void*)adms_module_valueto_jacobian;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'jacobian' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031itransform(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_admsmain)ai->_item.p)->_itransform)); d->_valueto=(void*)adms_admsmain_valueto_itransform;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'itransform' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031case(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_case)); d->_valueto=(void*)adms_module_valueto_case;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_case)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_case)ai->_item.p)->_case); d->_valueto=(void*)adms_case_valueto_case;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'case' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031ddxprobe(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA1*/ p_admst d1=adms_admst_newla(d0,ai,((p_variableprototype)d0->_item.p)->_ddxprobe);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_ddxprobe;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_variableprototype)ai->_item.p)->_ddxprobe)); d->_valueto=(void*)adms_variableprototype_valueto_ddxprobe;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'ddxprobe' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031obsolete(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_obsolete); d->_valueto=(void*)adms_admsmain_valueto_obsolete;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'obsolete' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031ddx(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_ddx); d->_valueto=(void*)adms_simulator_valueto_ddx;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'ddx' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031ddt_name(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nature)ai->_item.p)->_ddt_name); d->_valueto=(void*)adms_nature_valueto_ddt_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'ddt_name' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031arg3(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_ternary)ai->_item.p)->_arg3); d->_valueto=(void*)adms_mapply_ternary_valueto_arg3;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'arg3' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031c(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_lexval)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_lexval)ai->_item.p)->_c); d->_valueto=(void*)adms_lexval_valueto_c;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'c' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031debug(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_debug); d->_valueto=(void*)adms_admsmain_valueto_debug;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'debug' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031arg2(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_binary)ai->_item.p)->_arg2); d->_valueto=(void*)adms_mapply_binary_valueto_arg2;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_ternary)ai->_item.p)->_arg2); d->_valueto=(void*)adms_mapply_ternary_valueto_arg2;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'arg2' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031else(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_conditional)ai->_item.p)->_else); d->_valueto=(void*)adms_conditional_valueto_else;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'else' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031parameterset(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_instance)ai->_item.p)->_parameterset)); d->_valueto=(void*)adms_instance_valueto_parameterset;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'parameterset' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031index(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_array)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_array)ai->_item.p)->_index); d->_valueto=(void*)adms_array_valueto_index;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'index' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031block(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_block);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_block;
  }
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_block)); d->_valueto=(void*)adms_module_valueto_block;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)ai->_item.p)->_block); d->_valueto=(void*)adms_variableprototype_valueto_block;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_blockvariable)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_blockvariable)ai->_item.p)->_block); d->_valueto=(void*)adms_blockvariable_valueto_block;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_block)ai->_item.p)->_block); d->_valueto=(void*)adms_block_valueto_block;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'block' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031derivate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_derivate);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_derivate;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_derivate); d->_valueto=(void*)adms_variableprototype_valueto_derivate;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'derivate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031function(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_expression)ai->_item.p)->_function)); d->_valueto=(void*)adms_expression_valueto_function;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_callfunction)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_callfunction)ai->_item.p)->_function); d->_valueto=(void*)adms_callfunction_valueto_function;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'function' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031nnode(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branch)ai->_item.p)->_nnode); d->_valueto=(void*)adms_branch_valueto_nnode;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'nnode' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031supexpr(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_range)ai->_item.p)->_supexpr); d->_valueto=(void*)adms_range_valueto_supexpr;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'supexpr' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031usedinevaluate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedinevaluate);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedinevaluate;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedinevaluate); d->_valueto=(void*)adms_variableprototype_valueto_usedinevaluate;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedinevaluate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031itransforminsideapplytemplate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_admsmain)ai->_item.p)->_itransforminsideapplytemplate)); d->_valueto=(void*)adms_admsmain_valueto_itransforminsideapplytemplate;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'itransforminsideapplytemplate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031infinity(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_expression)ai->_item.p)->_infinity); d->_valueto=(void*)adms_expression_valueto_infinity;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'infinity' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031infexpr(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_range)ai->_item.p)->_infexpr); d->_valueto=(void*)adms_range_valueto_infexpr;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'infexpr' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031potential(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_discipline)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_discipline)ai->_item.p)->_potential); d->_valueto=(void*)adms_discipline_valueto_potential;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'potential' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031defaultcase(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_caseitem)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_caseitem)ai->_item.p)->_defaultcase); d->_valueto=(void*)adms_caseitem_valueto_defaultcase;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'defaultcase' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031value(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_number)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_number)ai->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_number_valueto_lexval;
    /*BBBB1*/ p_admst d1=adms_admst_newbs(d0,ai,((p_lexval)d0->_item.p)->_string);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newbr(ai,ai,((p_math)ai->_item.p)->_value); d->_valueto=(void*)adms_math_valueto_value;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_string)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_string)ai->_item.p)->_value); d->_valueto=(void*)adms_string_valueto_value;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_expression)ai->_item.p)->_value); d->_valueto=(void*)adms_expression_valueto_value;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instanceparameter)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instanceparameter)ai->_item.p)->_value); d->_valueto=(void*)adms_instanceparameter_valueto_value;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_return)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_return)ai->_item.p)->_value); d->_valueto=(void*)adms_return_valueto_value;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_attribute)
  {
    p_admst d=adms_admst_newpc(ai,ai,(p_attribute)ai->_item.p);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'value' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031tree(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_analogfunction)ai->_item.p)->_tree); d->_valueto=(void*)adms_analogfunction_valueto_tree;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_expression)ai->_item.p)->_tree); d->_valueto=(void*)adms_expression_valueto_tree;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'tree' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031instantiator(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_instantiator)); d->_valueto=(void*)adms_module_valueto_instantiator;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instance)ai->_item.p)->_instantiator); d->_valueto=(void*)adms_instance_valueto_instantiator;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'instantiator' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031usage(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_usage); d->_valueto=(void*)adms_admsmain_valueto_usage;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usage' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031update(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_forloop)ai->_item.p)->_update); d->_valueto=(void*)adms_forloop_valueto_update;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'update' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031dependency(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  else if(e==admse_string)
    e=admse_math;
  else if(e==admse_subexpression)
    e=admse_math;
  else if(e==admse_mapply_unary)
    e=admse_math;
  else if(e==admse_mapply_binary)
    e=admse_math;
  else if(e==admse_mapply_ternary)
    e=admse_math;
  else if(e==admse_number)
    e=admse_math;
  else if(e==admse_function)
    e=admse_math;
  else if(e==admse_variable)
    e=admse_math;
  else if(e==admse_array)
    e=admse_math;
  else if(e==admse_probe)
    e=admse_math;
  else if(e==admse_expression)
    e=admse_math;
  else if(e==admse_instance)
    e=admse_math;
  else if(e==admse_instanceparameter)
    e=admse_math;
  else if(e==admse_instancenode)
    e=admse_math;
  else if(e==admse_nilled)
    e=admse_math;
  else if(e==admse_assignment)
    e=admse_math;
  else if(e==admse_contribution)
    e=admse_math;
  else if(e==admse_conditional)
    e=admse_math;
  else if(e==admse_forloop)
    e=admse_math;
  else if(e==admse_whileloop)
    e=admse_math;
  else if(e==admse_case)
    e=admse_math;
  else if(e==admse_caseitem)
    e=admse_math;
  else if(e==admse_blockvariable)
    e=admse_math;
  else if(e==admse_block)
    e=admse_math;
  else if(e==admse_callfunction)
    e=admse_math;
  if(0) {}
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_dependency); d->_valueto=(void*)adms_variableprototype_valueto_dependency;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_math)ai->_item.p)->_dependency); d->_valueto=(void*)adms_math_valueto_dependency;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'dependency' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031whileloop(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_whileloop)); d->_valueto=(void*)adms_module_valueto_whileloop;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'whileloop' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031blockvariable(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_blockvariable)); d->_valueto=(void*)adms_module_valueto_blockvariable;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'blockvariable' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031then(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_conditional)ai->_item.p)->_then); d->_valueto=(void*)adms_conditional_valueto_then;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'then' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031analog(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_module)ai->_item.p)->_analog); d->_valueto=(void*)adms_module_valueto_analog;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'analog' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031nodefrommodule(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_instancenode)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instancenode)ai->_item.p)->_nodefrommodule); d->_valueto=(void*)adms_instancenode_valueto_nodefrommodule;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'nodefrommodule' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031whileblock(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_whileloop)ai->_item.p)->_whileblock); d->_valueto=(void*)adms_whileloop_valueto_whileblock;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'whileblock' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031usedinfinal(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedinfinal);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedinfinal;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedinfinal); d->_valueto=(void*)adms_variableprototype_valueto_usedinfinal;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedinfinal' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031default(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_default);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_default;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)ai->_item.p)->_default); d->_valueto=(void*)adms_variableprototype_valueto_default;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'default' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031evaluation(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_module)ai->_item.p)->_evaluation); d->_valueto=(void*)adms_module_valueto_evaluation;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'evaluation' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031sizetype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_sizetype);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_sizetype;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_sizetype); d->_valueto=(void*)adms_variableprototype_valueto_sizetype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'sizetype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031unique_id(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_function)ai->_item.p)->_unique_id); d->_valueto=(void*)adms_function_valueto_unique_id;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'unique_id' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031setinfinal(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setinfinal);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setinfinal;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setinfinal); d->_valueto=(void*)adms_variableprototype_valueto_setinfinal;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setinfinal' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031dbg_vla(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_dbg_vla); d->_valueto=(void*)adms_admsmain_valueto_dbg_vla;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'dbg_vla' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031type(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_type);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_type;
  }
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_analogfunction)ai->_item.p)->_type); d->_valueto=(void*)adms_analogfunction_valueto_type;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_type); d->_valueto=(void*)adms_variableprototype_valueto_type;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_type); d->_valueto=(void*)adms_source_valueto_type;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_range)ai->_item.p)->_type); d->_valueto=(void*)adms_range_valueto_type;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'type' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031currentdate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_currentdate); d->_valueto=(void*)adms_simulator_valueto_currentdate;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'currentdate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031if(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_conditional)ai->_item.p)->_if); d->_valueto=(void*)adms_conditional_valueto_if;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'if' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031setininitial_step(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setininitial_step);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setininitial_step;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setininitial_step); d->_valueto=(void*)adms_variableprototype_valueto_setininitial_step;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setininitial_step' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031parameter(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_instanceparameter)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_instanceparameter)ai->_item.p)->_parameter); d->_valueto=(void*)adms_instanceparameter_valueto_parameter;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'parameter' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031invtransform(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_admsmain)ai->_item.p)->_invtransform)); d->_valueto=(void*)adms_admsmain_valueto_invtransform;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'invtransform' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031lhs(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_assignment)ai->_item.p)->_lhs); d->_valueto=(void*)adms_assignment_valueto_lhs;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_contribution)ai->_item.p)->_lhs); d->_valueto=(void*)adms_contribution_valueto_lhs;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'lhs' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031TemperatureDependent(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_TemperatureDependent);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_TemperatureDependent;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_TemperatureDependent); d->_valueto=(void*)adms_variableprototype_valueto_TemperatureDependent;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_expression)ai->_item.p)->_TemperatureDependent); d->_valueto=(void*)adms_expression_valueto_TemperatureDependent;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'TemperatureDependent' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031scope(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_scope);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_scope;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_scope); d->_valueto=(void*)adms_variableprototype_valueto_scope;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'scope' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031column(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_jacobian)ai->_item.p)->_column); d->_valueto=(void*)adms_jacobian_valueto_column;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'column' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031warning(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_warning); d->_valueto=(void*)adms_admsmain_valueto_warning;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'warning' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031caseitem(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_case)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_case)ai->_item.p)->_caseitem)); d->_valueto=(void*)adms_case_valueto_caseitem;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'caseitem' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031valueof(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_admsmain)ai->_item.p)->_valueof)); d->_valueto=(void*)adms_admsmain_valueto_valueof;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'valueof' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031string(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_lexval)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_lexval)ai->_item.p)->_string); d->_valueto=(void*)adms_lexval_valueto_string;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'string' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031fpos(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_admsmain)ai->_item.p)->_fpos); d->_valueto=(void*)adms_admsmain_valueto_fpos;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'fpos' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031setingetprev(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setingetprev);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setingetprev;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setingetprev); d->_valueto=(void*)adms_variableprototype_valueto_setingetprev;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setingetprev' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031nature(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_admsmain)ai->_item.p)->_nature)); d->_valueto=(void*)adms_admsmain_valueto_nature;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_source)ai->_item.p)->_nature); d->_valueto=(void*)adms_source_valueto_nature;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_probe)ai->_item.p)->_nature); d->_valueto=(void*)adms_probe_valueto_nature;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'nature' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031verbose(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_verbose); d->_valueto=(void*)adms_admsmain_valueto_verbose;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'verbose' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031callfunction(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_callfunction)); d->_valueto=(void*)adms_module_valueto_callfunction;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'callfunction' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031conditional(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_conditional)); d->_valueto=(void*)adms_module_valueto_conditional;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'conditional' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031maxsize(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_maxsize);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_maxsize;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)ai->_item.p)->_maxsize); d->_valueto=(void*)adms_variableprototype_valueto_maxsize;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'maxsize' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031argc(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_admsmain)ai->_item.p)->_argc); d->_valueto=(void*)adms_admsmain_valueto_argc;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'argc' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031setininstance(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setininstance);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setininstance;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setininstance); d->_valueto=(void*)adms_variableprototype_valueto_setininstance;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setininstance' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031idt_nature(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nature)ai->_item.p)->_idt_nature); d->_valueto=(void*)adms_nature_valueto_idt_nature;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'idt_nature' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031arguments(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_function)ai->_item.p)->_arguments)); d->_valueto=(void*)adms_function_valueto_arguments;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'arguments' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031definition(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_function)ai->_item.p)->_definition); d->_valueto=(void*)adms_function_valueto_definition;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'definition' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031input(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_input);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_input;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_input); d->_valueto=(void*)adms_variableprototype_valueto_input;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'input' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031probe(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA1*/ p_admst d1=adms_admst_newla(d0,ai,((p_variableprototype)d0->_item.p)->_probe);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_probe;
  }
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_simulator)ai->_item.p)->_probe); d->_valueto=(void*)adms_simulator_valueto_probe;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_probe)); d->_valueto=(void*)adms_module_valueto_probe;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_variableprototype)ai->_item.p)->_probe)); d->_valueto=(void*)adms_variableprototype_valueto_probe;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_source)ai->_item.p)->_probe)); d->_valueto=(void*)adms_source_valueto_probe;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_expression)ai->_item.p)->_probe)); d->_valueto=(void*)adms_expression_valueto_probe;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_block)ai->_item.p)->_probe)); d->_valueto=(void*)adms_block_valueto_probe;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'probe' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031arg1(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_mapply_unary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_unary)ai->_item.p)->_arg1); d->_valueto=(void*)adms_mapply_unary_valueto_arg1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_binary)ai->_item.p)->_arg1); d->_valueto=(void*)adms_mapply_binary_valueto_arg1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_mapply_ternary)ai->_item.p)->_arg1); d->_valueto=(void*)adms_mapply_ternary_valueto_arg1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'arg1' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031idt_name(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nature)ai->_item.p)->_idt_name); d->_valueto=(void*)adms_nature_valueto_idt_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'idt_name' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031usedinmodel(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_usedinmodel);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_usedinmodel;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_usedinmodel); d->_valueto=(void*)adms_variableprototype_valueto_usedinmodel;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'usedinmodel' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031infboundtype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_range)ai->_item.p)->_infboundtype); d->_valueto=(void*)adms_range_valueto_infboundtype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'infboundtype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031base(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_nature)ai->_item.p)->_base); d->_valueto=(void*)adms_nature_valueto_base;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'base' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031location(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_node)ai->_item.p)->_location); d->_valueto=(void*)adms_node_valueto_location;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'location' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031contribution(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_contribution)); d->_valueto=(void*)adms_module_valueto_contribution;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'contribution' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031row(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_jacobian)ai->_item.p)->_row); d->_valueto=(void*)adms_jacobian_valueto_row;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'row' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031f(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_lexval)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_lexval)ai->_item.p)->_f); d->_valueto=(void*)adms_lexval_valueto_f;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'f' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031l(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_lexval)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_lexval)ai->_item.p)->_l); d->_valueto=(void*)adms_lexval_valueto_l;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'l' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031sr1(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_simulator)ai->_item.p)->_sr1); d->_valueto=(void*)adms_simulator_valueto_sr1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'sr1' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031package_string(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_package_string); d->_valueto=(void*)adms_simulator_valueto_package_string;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'package_string' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031package_name(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_package_name); d->_valueto=(void*)adms_simulator_valueto_package_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'package_name' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031static(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  else if(e==admse_expression)
    e=admse_math;
  else if(e==admse_nilled)
    e=admse_math;
  else if(e==admse_assignment)
    e=admse_math;
  else if(e==admse_contribution)
    e=admse_math;
  else if(e==admse_conditional)
    e=admse_math;
  else if(e==admse_forloop)
    e=admse_math;
  else if(e==admse_whileloop)
    e=admse_math;
  else if(e==admse_case)
    e=admse_math;
  else if(e==admse_blockvariable)
    e=admse_math;
  else if(e==admse_block)
    e=admse_math;
  else if(e==admse_callfunction)
    e=admse_math;
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_static);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_static;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_static); d->_valueto=(void*)adms_variableprototype_valueto_static;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_static); d->_valueto=(void*)adms_source_valueto_static;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_jacobian)ai->_item.p)->_static); d->_valueto=(void*)adms_jacobian_valueto_static;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_math)ai->_item.p)->_static); d->_valueto=(void*)adms_math_valueto_static;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'static' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031diagonal(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_jacobian)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_jacobian)ai->_item.p)->_diagonal); d->_valueto=(void*)adms_jacobian_valueto_diagonal;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'diagonal' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031pnode(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_branch)ai->_item.p)->_pnode); d->_valueto=(void*)adms_branch_valueto_pnode;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'pnode' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031alias(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA1*/ p_admst d1=adms_admst_newla(d0,ai,((p_variableprototype)d0->_item.p)->_alias);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_alias;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_variableprototype)ai->_item.p)->_alias)); d->_valueto=(void*)adms_variableprototype_valueto_alias;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'alias' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031whitenoise(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_source)ai->_item.p)->_whitenoise); d->_valueto=(void*)adms_source_valueto_whitenoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_contribution)ai->_item.p)->_whitenoise); d->_valueto=(void*)adms_contribution_valueto_whitenoise;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'whitenoise' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031assignment(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA1*/ p_admst d1=adms_admst_newla(d0,ai,((p_variableprototype)d0->_item.p)->_assignment);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_assignment;
  }
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_assignment)); d->_valueto=(void*)adms_module_valueto_assignment;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_variableprototype)ai->_item.p)->_assignment)); d->_valueto=(void*)adms_variableprototype_valueto_assignment;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'assignment' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031package_version(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_package_version); d->_valueto=(void*)adms_simulator_valueto_package_version;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'package_version' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031developer(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_developer); d->_valueto=(void*)adms_simulator_valueto_developer;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'developer' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031br1(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_simulator)ai->_item.p)->_br1); d->_valueto=(void*)adms_simulator_valueto_br1;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'br1' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031hasspecialnumber(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_expression)ai->_item.p)->_hasspecialnumber); d->_valueto=(void*)adms_expression_valueto_hasspecialnumber;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'hasspecialnumber' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031prototype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); d->_valueto=(void*)adms_variable_valueto_prototype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'prototype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031class(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_function)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_function)ai->_item.p)->_class); d->_valueto=(void*)adms_function_valueto_class;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'class' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031analogfunction(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_analogfunction)); d->_valueto=(void*)adms_module_valueto_analogfunction;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'analogfunction' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031dbg_mem(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_dbg_mem); d->_valueto=(void*)adms_admsmain_valueto_dbg_mem;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'dbg_mem' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031minsize(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_minsize);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_minsize;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)ai->_item.p)->_minsize); d->_valueto=(void*)adms_variableprototype_valueto_minsize;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'minsize' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031argv(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_admsmain)ai->_item.p)->_argv)); d->_valueto=(void*)adms_admsmain_valueto_argv;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'argv' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031tmp(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_tmp); d->_valueto=(void*)adms_simulator_valueto_tmp;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'tmp' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031transform(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_admsmain)ai->_item.p)->_transform)); d->_valueto=(void*)adms_admsmain_valueto_transform;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'transform' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031code(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_analog)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_analog)ai->_item.p)->_code); d->_valueto=(void*)adms_analog_valueto_code;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_caseitem)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_caseitem)ai->_item.p)->_code); d->_valueto=(void*)adms_caseitem_valueto_code;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'code' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031isstate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_isstate);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_isstate;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_isstate); d->_valueto=(void*)adms_variableprototype_valueto_isstate;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'isstate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031attribute(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA1*/ p_admst d1=adms_admst_newla(d0,ai,((p_variableprototype)d0->_item.p)->_attribute);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_attribute;
  }
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_attribute)); d->_valueto=(void*)adms_module_valueto_attribute;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_analogfunction)ai->_item.p)->_attribute)); d->_valueto=(void*)adms_analogfunction_valueto_attribute;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_node)ai->_item.p)->_attribute)); d->_valueto=(void*)adms_node_valueto_attribute;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branch)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_branch)ai->_item.p)->_attribute)); d->_valueto=(void*)adms_branch_valueto_attribute;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_variableprototype)ai->_item.p)->_attribute)); d->_valueto=(void*)adms_variableprototype_valueto_attribute;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_source)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_source)ai->_item.p)->_attribute)); d->_valueto=(void*)adms_source_valueto_attribute;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_math)ai->_item.p)->_attribute)); d->_valueto=(void*)adms_math_valueto_attribute;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_assignment)ai->_item.p)->_attribute)); d->_valueto=(void*)adms_assignment_valueto_attribute;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_contribution)ai->_item.p)->_attribute)); d->_valueto=(void*)adms_contribution_valueto_attribute;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_block)ai->_item.p)->_attribute)); d->_valueto=(void*)adms_block_valueto_attribute;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'attribute' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031output(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_output);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_output;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_output); d->_valueto=(void*)adms_variableprototype_valueto_output;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'output' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031source(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_source)); d->_valueto=(void*)adms_module_valueto_source;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_probe)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_probe)ai->_item.p)->_source); d->_valueto=(void*)adms_probe_valueto_source;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'source' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031info(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_info); d->_valueto=(void*)adms_admsmain_valueto_info;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'info' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031item(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_list)
  {
    p_admst d=adms_admst_newln(ai,ai,((p_list)ai->_item.p)->_item); d->_valueto=(void*)adms_list_valueto_item;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_block)ai->_item.p)->_item)); d->_valueto=(void*)adms_block_valueto_item;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'item' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031access(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nature)ai->_item.p)->_access); d->_valueto=(void*)adms_nature_valueto_access;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'access' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031direction(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_node)ai->_item.p)->_direction); d->_valueto=(void*)adms_node_valueto_direction;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'direction' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031domain(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_discipline)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_discipline)ai->_item.p)->_domain); d->_valueto=(void*)adms_discipline_valueto_domain;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'domain' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031nodealias(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_nodealias)); d->_valueto=(void*)adms_module_valueto_nodealias;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'nodealias' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031insource(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_insource);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_insource;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_insource); d->_valueto=(void*)adms_variableprototype_valueto_insource;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'insource' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031hasVoltageDependentFunction(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_expression)ai->_item.p)->_hasVoltageDependentFunction); d->_valueto=(void*)adms_expression_valueto_hasVoltageDependentFunction;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'hasVoltageDependentFunction' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031setinevaluate(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_setinevaluate);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_setinevaluate;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_setinevaluate); d->_valueto=(void*)adms_variableprototype_valueto_setinevaluate;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'setinevaluate' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031parametertype(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newbe(d0,ai,((p_variableprototype)d0->_item.p)->_parametertype);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_parametertype;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_variableprototype)ai->_item.p)->_parametertype); d->_valueto=(void*)adms_variableprototype_valueto_parametertype;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'parametertype' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031name(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_analogfunction)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_analogfunction)ai->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_analogfunction_valueto_lexval;
    /*BBBB1*/ p_admst d1=adms_admst_newbs(d0,ai,((p_lexval)d0->_item.p)->_string);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_variableprototype)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variableprototype)ai->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variableprototype_valueto_lexval;
    /*BBBB1*/ p_admst d1=adms_admst_newbs(d0,ai,((p_lexval)d0->_item.p)->_string);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_function)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_function)ai->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_function_valueto_lexval;
    /*BBBB1*/ p_admst d1=adms_admst_newbs(d0,ai,((p_lexval)d0->_item.p)->_string);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*BBBB1*/ p_admst d1=adms_admst_newpa(d0,ai,(p_adms)((p_variableprototype)d0->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d1); d1->_valueto=(void*)adms_variableprototype_valueto_lexval;
    /*BBBB1*/ p_admst d2=adms_admst_newbs(d1,ai,((p_lexval)d1->_item.p)->_string);if(d2->_preva) d2->_preva->_nexta=d2->_nexta,d2->_preva=NULL; if(d2->_nexta) d2->_nexta->_preva=d2->_preva,d2->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d2; else p->_an->_nexta=d2,d2->_preva=p->_an,p->_an=d2;d2->_position=++p->_position;d2->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_block)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_block)ai->_item.p)->_lexval); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_block_valueto_lexval;
    /*BBBB1*/ p_admst d1=adms_admst_newbs(d0,ai,((p_lexval)d0->_item.p)->_string);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_lexval_valueto_string;
  }
  else if(e==admse_simulator)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_simulator)ai->_item.p)->_name); d->_valueto=(void*)adms_simulator_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_admsmain)ai->_item.p)->_name); d->_valueto=(void*)adms_admsmain_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nature)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nature)ai->_item.p)->_name); d->_valueto=(void*)adms_nature_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_discipline)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_discipline)ai->_item.p)->_name); d->_valueto=(void*)adms_discipline_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_module)ai->_item.p)->_name); d->_valueto=(void*)adms_module_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nodealias)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nodealias)ai->_item.p)->_name); d->_valueto=(void*)adms_nodealias_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_node)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_node)ai->_item.p)->_name); d->_valueto=(void*)adms_node_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_branchalias)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_branchalias)ai->_item.p)->_name); d->_valueto=(void*)adms_branchalias_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_range)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_range)ai->_item.p)->_name); d->_valueto=(void*)adms_range_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_math)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_math)ai->_item.p)->_name); d->_valueto=(void*)adms_math_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_unary)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_mapply_unary)ai->_item.p)->_name); d->_valueto=(void*)adms_mapply_unary_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_binary)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_mapply_binary)ai->_item.p)->_name); d->_valueto=(void*)adms_mapply_binary_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_mapply_ternary)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_mapply_ternary)ai->_item.p)->_name); d->_valueto=(void*)adms_mapply_ternary_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_instance)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_instance)ai->_item.p)->_name); d->_valueto=(void*)adms_instance_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_nilled)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_nilled)ai->_item.p)->_name); d->_valueto=(void*)adms_nilled_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_assignment)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_assignment)ai->_item.p)->_name); d->_valueto=(void*)adms_assignment_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_contribution)ai->_item.p)->_name); d->_valueto=(void*)adms_contribution_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_conditional)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_conditional)ai->_item.p)->_name); d->_valueto=(void*)adms_conditional_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_forloop)ai->_item.p)->_name); d->_valueto=(void*)adms_forloop_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_whileloop)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_whileloop)ai->_item.p)->_name); d->_valueto=(void*)adms_whileloop_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_case)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_case)ai->_item.p)->_name); d->_valueto=(void*)adms_case_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_return)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_return)ai->_item.p)->_name); d->_valueto=(void*)adms_return_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_attribute)
  {
    p_admst d=adms_admst_newbs(ai,ai,((p_attribute)ai->_item.p)->_name); d->_valueto=(void*)adms_attribute_valueto_name;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'name' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031curline(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbi(ai,ai,((p_admsmain)ai->_item.p)->_curline); d->_valueto=(void*)adms_admsmain_valueto_curline;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'curline' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031variable(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_variable)
  {
    /*BBBB1*/ p_admst d0=adms_admst_newpa(ai,ai,(p_adms)((p_variable)ai->_item.p)->_prototype); adms_slist_push(&p->_aliasadmst,(p_adms)d0); d0->_valueto=(void*)adms_variable_valueto_prototype;
    /*AAAA1*/ p_admst d1=adms_admst_newla(d0,ai,((p_variableprototype)d0->_item.p)->_variable);if(d1->_preva) d1->_preva->_nexta=d1->_nexta,d1->_preva=NULL; if(d1->_nexta) d1->_nexta->_preva=d1->_preva,d1->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d1; else p->_an->_nexta=d1,d1->_preva=p->_an,p->_an=d1;d1->_position=++p->_position;d1->_valueto=(void*)adms_variableprototype_valueto_variable;
  }
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_admsmain)ai->_item.p)->_variable)); d->_valueto=(void*)adms_admsmain_valueto_variable;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_variable)); d->_valueto=(void*)adms_module_valueto_variable;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_analogfunction)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_analogfunction)ai->_item.p)->_variable)); d->_valueto=(void*)adms_analogfunction_valueto_variable;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_variableprototype)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_variableprototype)ai->_item.p)->_variable)); d->_valueto=(void*)adms_variableprototype_valueto_variable;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_array)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_array)ai->_item.p)->_variable); d->_valueto=(void*)adms_array_valueto_variable;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_expression)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_expression)ai->_item.p)->_variable)); d->_valueto=(void*)adms_expression_valueto_variable;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_blockvariable)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_blockvariable)ai->_item.p)->_variable)); d->_valueto=(void*)adms_blockvariable_valueto_variable;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_block)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_block)ai->_item.p)->_variable)); d->_valueto=(void*)adms_block_valueto_variable;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_evaluation)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_evaluation)ai->_item.p)->_variable)); d->_valueto=(void*)adms_evaluation_valueto_variable;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'variable' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031branchalias(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_module)
  {
    p_admst d=adms_admst_newla(ai,ai,(p_slist)(((p_module)ai->_item.p)->_branchalias)); d->_valueto=(void*)adms_module_valueto_branchalias;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else if(e==admse_contribution)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_contribution)ai->_item.p)->_branchalias); d->_valueto=(void*)adms_contribution_valueto_branchalias;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'branchalias' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031fatal(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_admsmain)
  {
    p_admst d=adms_admst_newbe(ai,ai,((p_admsmain)ai->_item.p)->_fatal); d->_valueto=(void*)adms_admsmain_valueto_fatal;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'fatal' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}
static void location031initial(p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst ai=aread(dot);
  admse e;
  if(ai)
    e=ai->_pseudo;
  else
  {
    p_admst d=adms_admst_newpa(ai,ai,NULL);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position; return;
  }
  if(0) {}
  if(0) {}
  else if(e==admse_forloop)
  {
    p_admst d=adms_admst_newpa(ai,ai,(p_adms)((p_forloop)ai->_item.p)->_initial); d->_valueto=(void*)adms_forloop_valueto_initial;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  else
  {
    p_admst d=adms_admst_newpn(ai,ai,ai);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    adms_message_error(("%s: 'initial' bad attribute\n",adms_transform_uid(p->_transform)))
  }
}


static void groupage (void) {}
static void location04 (void) {}
static void location05 (void) {}

p_slist globalfileoutputlist=NULL;
int break_found=0;

FILE *OUT (void)
{
  return globalfileoutputlist?(FILE*)globalfileoutputlist->data:stdout;
}
p_transform lookfortemplates(p_transform mytransform,const char*match)
{
  p_slist li;
  p_transform parent=root()->_itransform?((p_itransform)root()->_itransform->data)->_originalcall:mytransform;
  while(parent)
  {
    p_slist l;
    for(l=parent->_templates;l;l=l->next)
      if(!strcmp(((p_admst)((p_transform)l->data)->_textmatch->_token->data)->_item.s,match))
        return (p_transform)l->data;
    parent=parent->_parent;
  }
  for(li=root()->_invtransform;li;li=li->next)
  {
    p_slist l;
    parent=(p_transform)li->data;
    for(l=parent->_templates;l;l=l->next)
      if(!strcmp(((p_admst)((p_transform)l->data)->_textmatch->_token->data)->_item.s,match))
        return (p_transform)l->data;
  }
  parent=mytransform;
  while(parent)
  {
    p_slist l;
    for(l=parent->_templates;l;l=l->next)
      if(!strcmp(((p_admst)((p_transform)l->data)->_textmatch->_token->data)->_item.s,match))
        return (p_transform)l->data;
    parent=parent->_parent;
  }
  return NULL;
}
static void location02 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_itransform myitransform=adms_itransform_new(mypath->_template);
  p_ptraverse p0=bar(dot,(p_path)mypath->_u->data);
  p_slist myl0=p0->_admst;
  myitransform->_originalcall=mypath->_transform;
  adms_slist_push(&root()->_itransform,(p_adms)myitransform);
  for(;myl0;myl0=myl0->next)
  {
    if(myl0->data&&((p_admst)myl0->data)->_item.p)
    {
      p_slist l;
      xtraverse(myitransform->_template->_children,(p_admst)myl0->data,dot);
      for(l=myitransform->_variable;l;l=l->next)
      {
        p_slist li;
        for(li=((p_admstvariable)l->data)->_value;li;li=li->next)
          deref((p_admst)li->data);
        adms_admstvariable_free((p_admstvariable)l->data);
      }
    }
  }
  adms_slist_pull(&root()->_itransform);
  free_ptraverse(p0);
  for(myl0=myitransform->_return;myl0;myl0=myl0->next)
  {
    if(((p_admst)myl0->data)->_preva) ((p_admst)myl0->data)->_preva->_nexta=((p_admst)myl0->data)->_nexta,((p_admst)myl0->data)->_preva=NULL; if(((p_admst)myl0->data)->_nexta) ((p_admst)myl0->data)->_nexta->_preva=((p_admst)myl0->data)->_preva,((p_admst)myl0->data)->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=((p_admst)myl0->data); else p->_an->_nexta=((p_admst)myl0->data),((p_admst)myl0->data)->_preva=p->_an,p->_an=((p_admst)myl0->data);((p_admst)myl0->data)->_position=++p->_position;
  }
  adms_itransform_free(myitransform);
}
void Xassert (p_transform mytransform,p_admst dot,p_admst dotdot)
{
  if(!mytransform->_textformat)
  {
    adms_message_fatal_continue(("assert failed\n"))
    adms_message_fatal(("see %s\n",adms_transform_uid(mytransform)))
  }
  else if(mytransform->_pathselect)
  {
    p_ptraverse pselect=bar(dot,mytransform->_pathselect);
    p_slist myli;
    for(myli=pselect->_admst;myli;myli=myli->next)
    {
      char* text=tsprintf((p_admst)myli->data,mytransform->_textformat);
      adms_message_fatal_continue(("%s",text))
      free(text);
    }
    adms_message_fatal(("see %s\n",adms_transform_uid(mytransform)))
    free_ptraverse(pselect);
  }
  else
  {
    char* text=tsprintf(dot,mytransform->_textformat);
    adms_message_fatal_continue(("%s",text))
    adms_message_fatal(("see %s\n",adms_transform_uid(mytransform)))
    free(text);
  }
}
typedef void (*p_transform_evaluate) (p_transform mytransform,p_admst dot);
void xtraverse (p_slist mytransforms,p_admst dot,p_admst dotdot)
{
  p_slist l;
  for(l=mytransforms;l;l=l->next)
  {
    int mypassed=1;
    p_transform mytransform=(p_transform)l->data;
    if(mytransform->_pathtest)
    {
      p_ptraverse myptraverse=bar(dot,mytransform->_pathtest);
      if(mytransform->_callback==(void*)Xassert)
        mypassed=!myptraverse->_admst;
      else
      {
        p_admst myadmst0;
        mypassed=(myptraverse->_admst&&(myadmst0=aread((p_admst)myptraverse->_admst->data))&&(myadmst0->_pseudo!=admse_empty));
      }
      free_ptraverse(myptraverse);
    }
    if(mypassed)
      ((p_transform_evaluate)mytransform->_callback)(mytransform,dot);
    if(break_found==1)
      break;
  }
}

static void root00 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newpa(dot,dot,(p_adms)root());if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
void location03 (void) {}
 /*[nepasimprimer]*/
static void adms_fatal_on_obsolete_syntax(p_transform mytransform,p_admst myadmst)
{
  if(myadmst&&
    ((myadmst->_pseudo==admse_datatypename)
     ||(myadmst->_pseudo==admse_empty)
     ||(myadmst->_pseudo==admse_basicenumeration)
     ||(myadmst->_pseudo==admse_basicinteger)
     ||(myadmst->_pseudo==admse_basicreal)
     ||(myadmst->_pseudo==admse_basicstring)))
    return;
  if(myadmst&&(myadmst->_pseudo==admse_expression))
  {
    adms_message_warning_continue(("[removed feature] admst:value-of 'expression'\n"))
    adms_message_warning_continue(("[removed feature] Please use admst:apply-templates\n"))
    adms_message_warning_continue(("[removed feature] see: %s\n",adms_transform_uid(mytransform)))
    adms_message_warning(("[removed feature] For help contact me at r29173@users.sourceforge.net\n"))
  }
  else if(myadmst->_pseudo==admse__arguments)
  {
    adms_message_warning_continue(("[removed feature] admst:value-of 'arguments'\n"))
    adms_message_warning_continue(("[removed feature] Please use admst:apply-templates\n"))
    adms_message_warning_continue(("[removed feature] see: %s\n",adms_transform_uid(mytransform)))
    adms_message_warning(("[removed feature] For help contact me at r29173@users.sourceforge.net\n"))
  }
}
p_admst adms_pull_admst (p_transform mytransform)
{
  if(root()->_valueof)
  {
    adms_slist_pull(&root()->_valueof); /*pull transform*/
    return (p_admst)adms_slist_pull(&root()->_valueof);
  }
  adms_message_fatal_continue(("stack '%%s' has no more element!\n"))
  adms_message_fatal(("see %s",adms_transform_uid(mytransform)))
  return NULL;
}
p_admstvariable lookup_dollar (const char* myid)
{
  p_itransform myitransform=root()->_itransform?(p_itransform)root()->_itransform->data:NULL;
  p_slist list;
  if(myitransform)
  {
    list=myitransform->_variable;
    while(list)
    {
      if(!strcmp(((p_admstvariable)list->data)->_name,myid))
        return (p_admstvariable)list->data;
      list=list->next;
    }
  }
  list=root()->_variable;
  while(list)
  {
    if(!strcmp(((p_admstvariable)list->data)->_name,myid))
      return (p_admstvariable)list->data;
    list=list->next;
  }
  return NULL;
}
char* tsprintf (p_kadmst myadmst, p_ktext mytext)
{
  char* myvalue=myadmst?adms_kclone(""):((p_admst)mytext->_token->data)->_item.s;
  p_slist myl;
  for(myl=((myadmst&&mytext)?mytext->_token:NULL);myl;myl=myl->next)
  {
    p_adms token=myl->data;
    if(token->_datatypename==admse_text)
    {
      if(((p_text)token)->_admse==admse__s)
      {
        p_admst mystack=adms_pull_admst(mytext->_transform);
        if(mystack)
        {
          char* mynewvalue=aprintf(mytext->_transform,mystack);
          if(mynewvalue)
          {
            adms_fatal_on_obsolete_syntax(mytext->_transform,mystack);
            adms_k2strconcat(&myvalue,mynewvalue);
            free(mynewvalue);
          }
          deref(mystack);
        }
      }
      else
      {
        char* dollarname=tsprintf(myadmst,(p_text)token);
        p_admstvariable dollar=lookup_dollar(dollarname);
        if(dollar)
        {
          p_slist myl2=dollar->_value;
          for(;myl2;myl2=myl2->next)
          {
            char* val=aprintf(mytext->_transform,(p_admst)myl2->data);
            if(val)
            {
              adms_k2strconcat(&myvalue,val);
              free(val);
            }
          }
        }
        else
        {
          adms_message_obsolete_continue(("variable $(%s) is undefined\n",dollarname))
          adms_message_obsolete(("Check if you really wanted to access an variable. If not replace '$' by '$'\n"))
          adms_message_obsolete(("see %s\n",adms_transform_uid(mytext->_transform)))
          adms_k2strconcat(&myvalue,"$");
          adms_k2strconcat(&myvalue,dollarname);
        }
        free(dollarname);
      }
    }
    else if(token->_datatypename==admse_admst)
      adms_k2strconcat(&myvalue,((p_admst)token)->_item.s);
    else if(token->_datatypename==admse_path)
    {
      p_ptraverse myptraverse=bar(myadmst,(p_path)token);
      p_slist myl;
      for(myl=myptraverse->_admst;myl;myl=myl->next)
      {
        char* mynewvalue=aprintf(((p_path)token)->_transform,(p_admst)myl->data);
        if(mynewvalue)
          adms_k2strconcat(&myvalue,mynewvalue);
        free(mynewvalue);
      }
      free_ptraverse(myptraverse);
    }
  }
  return myvalue;
}
void tprintf (p_kadmst myadmst, p_ktext mytext)
{
  p_slist myl;
  for(myl=mytext->_token;myl;myl=myl->next)
  {
    p_adms token=myl->data;
    if(token->_datatypename==admse_text)
    {
      if(((p_text)token)->_admse==admse__s)
      {
        p_admst mystack=adms_pull_admst(mytext->_transform);
        if(mystack)
        {
          char* mynewvalue=aprintf(mytext->_transform,mystack);
          if(mynewvalue)
          {
            adms_fatal_on_obsolete_syntax(mytext->_transform,mystack);
            fputs(mynewvalue,OUT());
            free(mynewvalue);
          }
          deref(mystack);
        }
      }
      else
      {
        char* dollarname=tsprintf(myadmst,(p_text)token);
        p_admstvariable dollar=lookup_dollar(dollarname);
        if(dollar)
        {
          p_slist myl2=dollar->_value;
          for(;myl2;myl2=myl2->next)
          {
            char* val=aprintf(mytext->_transform,(p_admst)myl2->data);
            if(val)
            {
              fputs(val,OUT());
              free(val);
            }
          }
        }
        else
        {
          adms_message_obsolete_continue(("variable $(%s) is undefined\n",dollarname))
          adms_message_obsolete(("Check if you really wanted to access an variable. If not replace '$' by '$'\n"))
          adms_message_obsolete(("see %s\n",adms_transform_uid(mytext->_transform)))
          fputs("$",OUT());
          fputs(dollarname,OUT());
        }
        free(dollarname);
      }
    }
    else if(token->_datatypename==admse_admst)
      fputs(((p_admst)token)->_item.s,OUT());
    else if(token->_datatypename==admse_path)
    {
      p_ptraverse myptraverse=bar(myadmst,(p_path)token);
      p_slist myl;
      for(myl=myptraverse->_admst;myl;myl=myl->next)
      {
        char* mynewvalue=aprintf(((p_path)token)->_transform,(p_admst)myl->data);
        if(mynewvalue)
          fputs(mynewvalue,OUT());
        free(mynewvalue);
      }
      free_ptraverse(myptraverse);
    }
  }
}
static void location26 (p_ptraverse p,p_path mypath,p_admst dot)
{
  tprintf(dot,mypath->_text);
}
static int retdatatypename(p_admst myadmst)
{
  if(
      (myadmst->_pseudo==admse_empty)
      ||
      (myadmst->_pseudo==admse_basicenumeration)
      ||
      (myadmst->_pseudo==admse_basicinteger)
      ||
      (myadmst->_pseudo==admse_basicreal)
      ||
      (myadmst->_pseudo==admse_basicstring)
      ||
      (myadmst->_pseudo==admse__ladms)
      ||
      (myadmst->_pseudo==admse__ladmst)
      ||
      (myadmst->_pseudo==admse_datatypename)
    )
    return myadmst->_pseudo;
  else if(myadmst->_pseudo==admse__croix)
    return ((p_attribute)myadmst->_item.p)->_value?((p_admst)((p_attribute)myadmst->_item.p)->_value)->_pseudo:admse_empty;
  else
    return myadmst->_item.p->_datatypename;
}
static p_attribute retcroixcroix (p_admst myadmst,p_path mypath)
{
  char*myname=tsprintf(myadmst,mypath->_text);
  p_attribute myattribute=adms_attribute_new(myname);
  free(myname);
  return myattribute;
}
static p_attribute retcroix (p_admst myadmst,p_path mypath)
{
  p_attribute myattribute=NULL;
  char*myname=tsprintf(myadmst,mypath->_text);
  p_slist list;
  p_adms item=myadmst->_item.p;
  if(
      (myadmst->_pseudo==admse_basicenumeration)
      ||
      (myadmst->_pseudo==admse_basicinteger)
      ||
      (myadmst->_pseudo==admse_basicreal)
      ||
      (myadmst->_pseudo==admse_basicstring)
      ||
      (myadmst->_pseudo==admse_datatypename)
    )
  {
    adms_message_fatal_continue(("operator '#' applied to element '%s' - not supported!\n",ns_etostr(myadmst->_pseudo)))
    adms_message_fatal(("see %s\n",adms_transform_uid(mypath->_transform)))
  }
  list=item?item->_attribute:NULL;
  for(;list&&!myattribute;list=list->next)
    if(!strcmp(((p_attribute)list->data)->_name,myname))
      myattribute=(p_attribute)list->data;
  if(!myattribute)
  {
    myattribute=adms_attribute_new(myname);
    adms_slist_push(&item->_attribute,(p_adms)myattribute);
  }
  free(myname);
  return myattribute;
}
static p_slist retcroixstar (p_admst myadmst)
{
  return myadmst->_item.p?myadmst->_item.p->_attribute:NULL;
}
static int adms_slist_compare (p_admst myadmst0,p_admst myadmst1)
{
  admse mytype0=myadmst0->_pseudo;
  admse mytype1=myadmst1->_pseudo;
  if((mytype0==admse_empty)&&(mytype1==admse_empty))
    return 0;
  else if(mytype0==admse_empty)
    return -1;
  else if(mytype1==admse_empty)
    return +1;
  else if((mytype0==admse_basicinteger)&&(mytype1==admse_basicinteger))
    return (myadmst0->_item.i-myadmst1->_item.i);
  else
  {
    char* uid1=aprintf(NULL,myadmst0);
    char* uid2=aprintf(NULL,myadmst1);
    int res=strcmp(uid1,uid2);
    free(uid1);
    free(uid2);
    return res;
  }
}
static p_slist adms_slist_sort_merge (p_slist myl0, p_slist myl1)
{
  t_slist list;
  p_slist myli=&list;
  while(myl0&&myl1)
  {
    if(adms_slist_compare((p_admst)myl0->data,(p_admst)myl1->data)<0)
    {
      myli=myli->next=myl0;
      myl0=myl0->next;
    }
    else
    {
      myli=myli->next=myl1;
      myl1=myl1->next;
    }
  }
  myli->next=myl0?myl0:myl1;
  return list.next;
}
static p_slist adms_slist_sort (p_slist list)
{
  p_slist myl0, myl1;
  if(!list)
    return NULL;
  if(!list->next)
    return list;
  myl0=list;
  myl1=list->next;
  while((myl1=myl1->next)!=NULL)
  {
    if((myl1=myl1->next)==NULL)
      break;
    myl0=myl0->next;
  }
  myl1=myl0->next;
  myl0->next=NULL;
  return adms_slist_sort_merge(adms_slist_sort(list),adms_slist_sort(myl1));
}
/*returned*/
static void location15 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist l;
  p_admst d=NULL;
  char* myname=tsprintf(dot,mypath->_text);
  p_itransform myitransform;
  if(!root()->_itransforminsideapplytemplate)
  {
    adms_message_fatal_continue(("return('%s') allowed only inside admst:apply-templates\n",myname))
    adms_message_fatal(("see %s\n",adms_transform_uid(mypath->_transform)))
  }
  myitransform=(p_itransform)root()->_itransforminsideapplytemplate->data;
  for(l=myitransform->_return;l&&!d;l=l->next)
    if(!strcmp(((p_return)((p_admst)l->data)->_item.p)->_name,myname))
      d=(p_admst)l->data;
  if(d==NULL)
  {
    adms_message_fatal_continue(("returned('%s'): undefined returned value\n",myname))
    adms_message_fatal(("see %s\n",adms_transform_uid(mypath->_transform)))
  }
  free(myname);
  if(d->_refd) d->_refd++;if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*"%p"*/
static void location200 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_pull_admst(mypath->_transform);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*'k'*/
static void location09k (p_ptraverse p,p_path mypath,p_admst dot)
{
  ((p_admst)mypath->_text->_token->data)->_previouspath=dot;
  if(((p_admst)mypath->_text->_token->data)->_preva) ((p_admst)mypath->_text->_token->data)->_preva->_nexta=((p_admst)mypath->_text->_token->data)->_nexta,((p_admst)mypath->_text->_token->data)->_preva=NULL; if(((p_admst)mypath->_text->_token->data)->_nexta) ((p_admst)mypath->_text->_token->data)->_nexta->_preva=((p_admst)mypath->_text->_token->data)->_preva,((p_admst)mypath->_text->_token->data)->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=((p_admst)mypath->_text->_token->data); else p->_an->_nexta=((p_admst)mypath->_text->_token->data),((p_admst)mypath->_text->_token->data)->_preva=p->_an,p->_an=((p_admst)mypath->_text->_token->data);((p_admst)mypath->_text->_token->data)->_position=++p->_position;
}
/*int*/
static void location10 (p_ptraverse p,p_path mypath,p_admst dot)
{
  ((p_admst)mypath->_text->_token->data)->_previouspath=dot;
  if(((p_admst)mypath->_text->_token->data)->_preva) ((p_admst)mypath->_text->_token->data)->_preva->_nexta=((p_admst)mypath->_text->_token->data)->_nexta,((p_admst)mypath->_text->_token->data)->_preva=NULL; if(((p_admst)mypath->_text->_token->data)->_nexta) ((p_admst)mypath->_text->_token->data)->_nexta->_preva=((p_admst)mypath->_text->_token->data)->_preva,((p_admst)mypath->_text->_token->data)->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=((p_admst)mypath->_text->_token->data); else p->_an->_nexta=((p_admst)mypath->_text->_token->data),((p_admst)mypath->_text->_token->data)->_preva=p->_an,p->_an=((p_admst)mypath->_text->_token->data);((p_admst)mypath->_text->_token->data)->_position=++p->_position;
}

static p_admstvariable retaroba (p_admst myadmst,p_path mypath)
{
  char* myid=tsprintf(myadmst,mypath->_text);
  p_admstvariable mydollar;
  p_slist list;
  p_adms item=myadmst->_item.p;
  list=item->_variable;
  while(list)
  {
    if(!strcmp(((p_admstvariable)list->data)->_name,myid))
    {
      free(myid);
      return (p_admstvariable)list->data;
    }
    list=list->next;
  }
  mydollar=adms_admstvariable_new(myid);
  adms_slist_push(&item->_variable,(p_adms)mydollar);
  free(myid);
  return mydollar;
}
static p_admstvariable retdollar (p_admst myadmst,p_path mypath)
{
  char* id=tsprintf(aread(myadmst),mypath->_text);
  p_admstvariable dollar=lookup_dollar(id);
  if(!dollar)
    adms_message_fatal(("variable $(%s) is undefined! see %s\n",id,adms_transform_uid(mypath->_transform)))
  free(id);
  return dollar;
}
static int retcount (p_admst myadmst,p_path mypath)
{
  p_ptraverse p0=bar(myadmst,(p_path)mypath->_u->data);
  int count=p0->_admst?((p_admst)p0->_admst->data)->_count:0;
  free_ptraverse(p0);
  return count;
}
/*datatypename*/
static void location03datatypename (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newbd(dot,dot,retdatatypename(dot));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*ident*/
static void location03dummy (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newbi(dot,dot,0);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*real*/
static void location07 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newbr(dot,dot,adms_strtod(mypath->_transform,tsprintf(NULL,mypath->_text)));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*position*/
static void location18 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newbi(dot,dot,(dot)->_position);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*count*/
static void location27 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newbi(dot,dot,retcount(dot,mypath));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*''*/
static void location09 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newns(dot,dot,tsprintf(dot,mypath->_text));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*##*/
static void location12 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newpa(dot,dot,(p_adms)retcroixcroix(dot,mypath));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*#*/
static void location13 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newpc(dot,dot,retcroix(dot,mypath));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*admst*/
static void location14 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newpa(dot,dot,(p_adms)dot);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*$var*/
static void location041 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newpd(dot,dot,retdollar(dot,mypath));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*@var*/
static void location051 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newpd(dot,dot,retaroba(dot,mypath));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
}
/*index*/
static int retindex (p_slist mylii,p_ptraverse p0)
{
  p_admst myadmst1=(p_admst)mylii->data;
  p_adms myadms1=myadmst1->_item.p;
  admse mytype1=myadmst1->_pseudo;
  p_cmp mycmp=adms_admsxml_cmp(myadmst1);
  p_slist myl0;
  int myindex=-1;
  int found=0;
  for(myl0=p0->_admst;myl0&&!found;myl0=myl0->next)
  {
    p_admst myadmst0=(p_admst)myl0->data;
    p_adms myadms0=myadmst0->_item.p;
    admse mytype0=myadmst0->_pseudo;
    found=(mytype0==mytype1)&&(!mycmp(myadms0,myadms1));
    myindex++;
  }
  if(found)
    return myindex;
  else
    return minusone;
}
static void location19 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_ptraverse p0=bar(dot,(p_path)mypath->_u->data);
  p_ptraverse p1=bar(dot,(p_path)mypath->_u->next->data);
  p_slist l1=p1->_admst;
  for(;l1;l1=l1->next)
  {
    p_admst d=adms_admst_newbi(dot,dot,retindex(l1,p0));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  free_ptraverse(p0); free_ptraverse(p1);
}

static char* retaprintf (p_path mypath,p_slist myl0)
{
  return aprintf(mypath->_transform,(p_admst)myl0->data);
}
static char* retpointer (p_slist myl0)
{
  char* mystring=malloc(sizeof(char)*50);
  sprintf(mystring,"%p",((p_admst)myl0->data)->_item.p);
  return mystring;
}
static char* retuc (p_path mypath,p_slist myl0)
{
  char* mystring=aprintf(mypath->_transform,(p_admst)myl0->data);
  adms_toupper(mystring);
  return mystring;
}
static char* retlc (p_path mypath,p_slist myl0)
{
  char* mystring=aprintf(mypath->_transform,(p_admst)myl0->data);
  adms_tolower(mystring);
  return mystring;
}
/*uid*/
static void location20 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_ptraverse p0=bar(dot,(p_path)mypath->_u->data);
  p_slist l0=p0->_admst;
  for(;l0;l0=l0->next)
  {
    p_admst d=adms_admst_newns(dot,dot,retaprintf(mypath,l0));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  free_ptraverse(p0);
}
/*id */
static void location21 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_ptraverse p0=bar(dot,(p_path)mypath->_u->data);
  p_slist l0=p0->_admst;
  for(;l0;l0=l0->next)
  {
    p_admst d=adms_admst_newns(dot,dot,retpointer(l0));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  free_ptraverse(p0);
}
/*uc*/
static void location24 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_ptraverse p0=bar(dot,(p_path)mypath->_u->data);
  p_slist l0=p0->_admst;
  for(;l0;l0=l0->next)
  {
    p_admst d=adms_admst_newns(dot,dot,retuc(mypath,l0));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  free_ptraverse(p0);
}
/*lc*/
static void location25 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_ptraverse p0=bar(dot,(p_path)mypath->_u->data);
  p_slist l0=p0->_admst;
  for(;l0;l0=l0->next)
  {
    p_admst d=adms_admst_newns(dot,dot,retlc(mypath,l0));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  free_ptraverse(p0);
}
/*sort*/
static void location22 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_ptraverse p0=bar(dot,(p_path)mypath->_u->data);
  p_slist lii=adms_slist_sort(p0->_admst);
  p0->_admst=lii;
  for(;lii;lii=lii->next)
  {
    p_admst d=adms_admst_newpn(dot,dot,(p_admst)lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  free_ptraverse(p0);
}
/*reverse*/
static void location23 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_ptraverse p0=bar(dot,(p_path)mypath->_u->data);
  p_slist lii=adms_slist_reverse(p0->_admst);
  p0->_admst=lii;
  for(;lii;lii=lii->next)
  {
    p_admst d=adms_admst_newpn(dot,dot,(p_admst)lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
  free_ptraverse(p0);
}
/*#**/
static void location130 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist lii=retcroixstar(dot)?retcroixstar(dot):NULL;
  for(;lii;lii=lii->next)
  {
    p_admst d=adms_admst_newpc(dot,dot,(p_attribute)lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
}
/*$var*/
static void location040 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist lii=retdollar(dot,mypath)->_value;
  for(;lii;lii=lii->next)
  {
    p_admst d=adms_admst_newpn(dot,dot,(p_admst)lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
}
/*@var*/
static void location050 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist lii=retaroba(dot,mypath)->_value;
  for(;lii;lii=lii->next)
  {
    p_admst d=adms_admst_newpn(dot,dot,(p_admst)lii->data);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
  }
}

static void attributecallback (p_path mypath0,p_slist npaths,p_slist npath)
{
  p_path mypath=(p_path)npath->data;
  mypath->_keeplist=(mypath0->_keeplist&&(npath->next==NULL)&&(mypath->_c==NULL))||mypath->_keeplist;
  if(mypath->_callback==(void*)location04)
  {
    mypath->_callback=(mypath->_keeplist)?(void*)location041:(void*)location040;
    mypath->_callbackname=(mypath->_keeplist)?"location041":"location040";
  }
  else if(mypath->_callback==(void*)location05)
  {
    mypath->_callback=(mypath->_keeplist)?(void*)location051:(void*)location050;
    mypath->_callbackname=(mypath->_keeplist)?"location051":"location050";
  }
  else if(mypath->_callback==(void*)location03)
  {
    if(0) {}
    else if(mypath->_text->_admse==admse_datatypename)
    {
      mypath->_callback=(void*)location03datatypename;
      mypath->_callbackname="location03datatypename.datatypename";
    }
    else if(mypath->_text->_admse==admse_attribute)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031attribute:(void*)location030attribute;
      mypath->_callbackname=(mypath->_keeplist)?"location031attribute":"location030attribute";
    }
    else if(mypath->_text->_admse==admse_variable)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031variable:(void*)location030variable;
      mypath->_callbackname=(mypath->_keeplist)?"location031variable":"location030variable";
    }
    else if(mypath->_text->_admse==admse_adms)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031adms:(void*)location030adms;
      mypath->_callbackname=(mypath->_keeplist)?"location031adms":"location030adms";
    }
    else if(mypath->_text->_admse==admse_name)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031name:(void*)location030name;
      mypath->_callbackname=(mypath->_keeplist)?"location031name":"location030name";
    }
    else if(mypath->_text->_admse==admse_currentdate)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031currentdate:(void*)location030currentdate;
      mypath->_callbackname=(mypath->_keeplist)?"location031currentdate":"location030currentdate";
    }
    else if(mypath->_text->_admse==admse_developer)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031developer:(void*)location030developer;
      mypath->_callbackname=(mypath->_keeplist)?"location031developer":"location030developer";
    }
    else if(mypath->_text->_admse==admse_fullname)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031fullname:(void*)location030fullname;
      mypath->_callbackname=(mypath->_keeplist)?"location031fullname":"location030fullname";
    }
    else if(mypath->_text->_admse==admse_package_name)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031package_name:(void*)location030package_name;
      mypath->_callbackname=(mypath->_keeplist)?"location031package_name":"location030package_name";
    }
    else if(mypath->_text->_admse==admse_package_tarname)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031package_tarname:(void*)location030package_tarname;
      mypath->_callbackname=(mypath->_keeplist)?"location031package_tarname":"location030package_tarname";
    }
    else if(mypath->_text->_admse==admse_package_version)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031package_version:(void*)location030package_version;
      mypath->_callbackname=(mypath->_keeplist)?"location031package_version":"location030package_version";
    }
    else if(mypath->_text->_admse==admse_package_string)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031package_string:(void*)location030package_string;
      mypath->_callbackname=(mypath->_keeplist)?"location031package_string":"location030package_string";
    }
    else if(mypath->_text->_admse==admse_package_bugreport)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031package_bugreport:(void*)location030package_bugreport;
      mypath->_callbackname=(mypath->_keeplist)?"location031package_bugreport":"location030package_bugreport";
    }
    else if(mypath->_text->_admse==admse_probe)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031probe:(void*)location030probe;
      mypath->_callbackname=(mypath->_keeplist)?"location031probe":"location030probe";
    }
    else if(mypath->_text->_admse==admse_tmp)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031tmp:(void*)location030tmp;
      mypath->_callbackname=(mypath->_keeplist)?"location031tmp":"location030tmp";
    }
    else if(mypath->_text->_admse==admse_tmp1)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031tmp1:(void*)location030tmp1;
      mypath->_callbackname=(mypath->_keeplist)?"location031tmp1":"location030tmp1";
    }
    else if(mypath->_text->_admse==admse_br1)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031br1:(void*)location030br1;
      mypath->_callbackname=(mypath->_keeplist)?"location031br1":"location030br1";
    }
    else if(mypath->_text->_admse==admse_br2)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031br2:(void*)location030br2;
      mypath->_callbackname=(mypath->_keeplist)?"location031br2":"location030br2";
    }
    else if(mypath->_text->_admse==admse_sr1)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031sr1:(void*)location030sr1;
      mypath->_callbackname=(mypath->_keeplist)?"location031sr1":"location030sr1";
    }
    else if(mypath->_text->_admse==admse_ddx)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031ddx:(void*)location030ddx;
      mypath->_callbackname=(mypath->_keeplist)?"location031ddx":"location030ddx";
    }
    else if(mypath->_text->_admse==admse_argc)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031argc:(void*)location030argc;
      mypath->_callbackname=(mypath->_keeplist)?"location031argc":"location030argc";
    }
    else if(mypath->_text->_admse==admse_fullfilename)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031fullfilename:(void*)location030fullfilename;
      mypath->_callbackname=(mypath->_keeplist)?"location031fullfilename":"location030fullfilename";
    }
    else if(mypath->_text->_admse==admse_filename)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031filename:(void*)location030filename;
      mypath->_callbackname=(mypath->_keeplist)?"location031filename":"location030filename";
    }
    else if(mypath->_text->_admse==admse_curfilename)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031curfilename:(void*)location030curfilename;
      mypath->_callbackname=(mypath->_keeplist)?"location031curfilename":"location030curfilename";
    }
    else if(mypath->_text->_admse==admse_curline)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031curline:(void*)location030curline;
      mypath->_callbackname=(mypath->_keeplist)?"location031curline":"location030curline";
    }
    else if(mypath->_text->_admse==admse_fpos)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031fpos:(void*)location030fpos;
      mypath->_callbackname=(mypath->_keeplist)?"location031fpos":"location030fpos";
    }
    else if(mypath->_text->_admse==admse_simulator)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031simulator:(void*)location030simulator;
      mypath->_callbackname=(mypath->_keeplist)?"location031simulator":"location030simulator";
    }
    else if(mypath->_text->_admse==admse_info)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031info:(void*)location030info;
      mypath->_callbackname=(mypath->_keeplist)?"location031info":"location030info";
    }
    else if(mypath->_text->_admse==admse_usage)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031usage:(void*)location030usage;
      mypath->_callbackname=(mypath->_keeplist)?"location031usage":"location030usage";
    }
    else if(mypath->_text->_admse==admse_verbose)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031verbose:(void*)location030verbose;
      mypath->_callbackname=(mypath->_keeplist)?"location031verbose":"location030verbose";
    }
    else if(mypath->_text->_admse==admse_hint)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031hint:(void*)location030hint;
      mypath->_callbackname=(mypath->_keeplist)?"location031hint":"location030hint";
    }
    else if(mypath->_text->_admse==admse_warning)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031warning:(void*)location030warning;
      mypath->_callbackname=(mypath->_keeplist)?"location031warning":"location030warning";
    }
    else if(mypath->_text->_admse==admse_obsolete)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031obsolete:(void*)location030obsolete;
      mypath->_callbackname=(mypath->_keeplist)?"location031obsolete":"location030obsolete";
    }
    else if(mypath->_text->_admse==admse_debug)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031debug:(void*)location030debug;
      mypath->_callbackname=(mypath->_keeplist)?"location031debug":"location030debug";
    }
    else if(mypath->_text->_admse==admse_dbg_vla)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031dbg_vla:(void*)location030dbg_vla;
      mypath->_callbackname=(mypath->_keeplist)?"location031dbg_vla":"location030dbg_vla";
    }
    else if(mypath->_text->_admse==admse_dbg_xml)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031dbg_xml:(void*)location030dbg_xml;
      mypath->_callbackname=(mypath->_keeplist)?"location031dbg_xml":"location030dbg_xml";
    }
    else if(mypath->_text->_admse==admse_error)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031error:(void*)location030error;
      mypath->_callbackname=(mypath->_keeplist)?"location031error":"location030error";
    }
    else if(mypath->_text->_admse==admse_fatal)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031fatal:(void*)location030fatal;
      mypath->_callbackname=(mypath->_keeplist)?"location031fatal":"location030fatal";
    }
    else if(mypath->_text->_admse==admse_dbg_mem)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031dbg_mem:(void*)location030dbg_mem;
      mypath->_callbackname=(mypath->_keeplist)?"location031dbg_mem":"location030dbg_mem";
    }
    else if(mypath->_text->_admse==admse_module)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031module:(void*)location030module;
      mypath->_callbackname=(mypath->_keeplist)?"location031module":"location030module";
    }
    else if(mypath->_text->_admse==admse_discipline)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031discipline:(void*)location030discipline;
      mypath->_callbackname=(mypath->_keeplist)?"location031discipline":"location030discipline";
    }
    else if(mypath->_text->_admse==admse_nature)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031nature:(void*)location030nature;
      mypath->_callbackname=(mypath->_keeplist)?"location031nature":"location030nature";
    }
    else if(mypath->_text->_admse==admse_argv)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031argv:(void*)location030argv;
      mypath->_callbackname=(mypath->_keeplist)?"location031argv":"location030argv";
    }
    else if(mypath->_text->_admse==admse_transform)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031transform:(void*)location030transform;
      mypath->_callbackname=(mypath->_keeplist)?"location031transform":"location030transform";
    }
    else if(mypath->_text->_admse==admse_invtransform)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031invtransform:(void*)location030invtransform;
      mypath->_callbackname=(mypath->_keeplist)?"location031invtransform":"location030invtransform";
    }
    else if(mypath->_text->_admse==admse_itransform)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031itransform:(void*)location030itransform;
      mypath->_callbackname=(mypath->_keeplist)?"location031itransform":"location030itransform";
    }
    else if(mypath->_text->_admse==admse_itransforminsideapplytemplate)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031itransforminsideapplytemplate:(void*)location030itransforminsideapplytemplate;
      mypath->_callbackname=(mypath->_keeplist)?"location031itransforminsideapplytemplate":"location030itransforminsideapplytemplate";
    }
    else if(mypath->_text->_admse==admse_valueof)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031valueof:(void*)location030valueof;
      mypath->_callbackname=(mypath->_keeplist)?"location031valueof":"location030valueof";
    }
    else if(mypath->_text->_admse==admse_datatype)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031datatype:(void*)location030datatype;
      mypath->_callbackname=(mypath->_keeplist)?"location031datatype":"location030datatype";
    }
    else if(mypath->_text->_admse==admse_item)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031item:(void*)location030item;
      mypath->_callbackname=(mypath->_keeplist)?"location031item":"location030item";
    }
    else if(mypath->_text->_admse==admse_access)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031access:(void*)location030access;
      mypath->_callbackname=(mypath->_keeplist)?"location031access":"location030access";
    }
    else if(mypath->_text->_admse==admse_abstol)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031abstol:(void*)location030abstol;
      mypath->_callbackname=(mypath->_keeplist)?"location031abstol":"location030abstol";
    }
    else if(mypath->_text->_admse==admse_base)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031base:(void*)location030base;
      mypath->_callbackname=(mypath->_keeplist)?"location031base":"location030base";
    }
    else if(mypath->_text->_admse==admse_ddt_name)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031ddt_name:(void*)location030ddt_name;
      mypath->_callbackname=(mypath->_keeplist)?"location031ddt_name":"location030ddt_name";
    }
    else if(mypath->_text->_admse==admse_ddt_nature)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031ddt_nature:(void*)location030ddt_nature;
      mypath->_callbackname=(mypath->_keeplist)?"location031ddt_nature":"location030ddt_nature";
    }
    else if(mypath->_text->_admse==admse_idt_name)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031idt_name:(void*)location030idt_name;
      mypath->_callbackname=(mypath->_keeplist)?"location031idt_name":"location030idt_name";
    }
    else if(mypath->_text->_admse==admse_idt_nature)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031idt_nature:(void*)location030idt_nature;
      mypath->_callbackname=(mypath->_keeplist)?"location031idt_nature":"location030idt_nature";
    }
    else if(mypath->_text->_admse==admse_units)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031units:(void*)location030units;
      mypath->_callbackname=(mypath->_keeplist)?"location031units":"location030units";
    }
    else if(mypath->_text->_admse==admse_flow)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031flow:(void*)location030flow;
      mypath->_callbackname=(mypath->_keeplist)?"location031flow":"location030flow";
    }
    else if(mypath->_text->_admse==admse_potential)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031potential:(void*)location030potential;
      mypath->_callbackname=(mypath->_keeplist)?"location031potential":"location030potential";
    }
    else if(mypath->_text->_admse==admse_domain)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031domain:(void*)location030domain;
      mypath->_callbackname=(mypath->_keeplist)?"location031domain":"location030domain";
    }
    else if(mypath->_text->_admse==admse_node)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031node:(void*)location030node;
      mypath->_callbackname=(mypath->_keeplist)?"location031node":"location030node";
    }
    else if(mypath->_text->_admse==admse_nodealias)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031nodealias:(void*)location030nodealias;
      mypath->_callbackname=(mypath->_keeplist)?"location031nodealias":"location030nodealias";
    }
    else if(mypath->_text->_admse==admse_branch)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031branch:(void*)location030branch;
      mypath->_callbackname=(mypath->_keeplist)?"location031branch":"location030branch";
    }
    else if(mypath->_text->_admse==admse_branchalias)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031branchalias:(void*)location030branchalias;
      mypath->_callbackname=(mypath->_keeplist)?"location031branchalias":"location030branchalias";
    }
    else if(mypath->_text->_admse==admse_analogfunction)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031analogfunction:(void*)location030analogfunction;
      mypath->_callbackname=(mypath->_keeplist)?"location031analogfunction":"location030analogfunction";
    }
    else if(mypath->_text->_admse==admse_instance)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031instance:(void*)location030instance;
      mypath->_callbackname=(mypath->_keeplist)?"location031instance":"location030instance";
    }
    else if(mypath->_text->_admse==admse_analog)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031analog:(void*)location030analog;
      mypath->_callbackname=(mypath->_keeplist)?"location031analog":"location030analog";
    }
    else if(mypath->_text->_admse==admse_block)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031block:(void*)location030block;
      mypath->_callbackname=(mypath->_keeplist)?"location031block":"location030block";
    }
    else if(mypath->_text->_admse==admse_blockvariable)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031blockvariable:(void*)location030blockvariable;
      mypath->_callbackname=(mypath->_keeplist)?"location031blockvariable":"location030blockvariable";
    }
    else if(mypath->_text->_admse==admse_assignment)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031assignment:(void*)location030assignment;
      mypath->_callbackname=(mypath->_keeplist)?"location031assignment":"location030assignment";
    }
    else if(mypath->_text->_admse==admse_callfunction)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031callfunction:(void*)location030callfunction;
      mypath->_callbackname=(mypath->_keeplist)?"location031callfunction":"location030callfunction";
    }
    else if(mypath->_text->_admse==admse_contribution)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031contribution:(void*)location030contribution;
      mypath->_callbackname=(mypath->_keeplist)?"location031contribution":"location030contribution";
    }
    else if(mypath->_text->_admse==admse_conditional)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031conditional:(void*)location030conditional;
      mypath->_callbackname=(mypath->_keeplist)?"location031conditional":"location030conditional";
    }
    else if(mypath->_text->_admse==admse_case)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031case:(void*)location030case;
      mypath->_callbackname=(mypath->_keeplist)?"location031case":"location030case";
    }
    else if(mypath->_text->_admse==admse_forloop)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031forloop:(void*)location030forloop;
      mypath->_callbackname=(mypath->_keeplist)?"location031forloop":"location030forloop";
    }
    else if(mypath->_text->_admse==admse_whileloop)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031whileloop:(void*)location030whileloop;
      mypath->_callbackname=(mypath->_keeplist)?"location031whileloop":"location030whileloop";
    }
    else if(mypath->_text->_admse==admse_instantiator)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031instantiator:(void*)location030instantiator;
      mypath->_callbackname=(mypath->_keeplist)?"location031instantiator":"location030instantiator";
    }
    else if(mypath->_text->_admse==admse_expression)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031expression:(void*)location030expression;
      mypath->_callbackname=(mypath->_keeplist)?"location031expression":"location030expression";
    }
    else if(mypath->_text->_admse==admse_jacobian)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031jacobian:(void*)location030jacobian;
      mypath->_callbackname=(mypath->_keeplist)?"location031jacobian":"location030jacobian";
    }
    else if(mypath->_text->_admse==admse_source)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031source:(void*)location030source;
      mypath->_callbackname=(mypath->_keeplist)?"location031source":"location030source";
    }
    else if(mypath->_text->_admse==admse_range)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031range:(void*)location030range;
      mypath->_callbackname=(mypath->_keeplist)?"location031range":"location030range";
    }
    else if(mypath->_text->_admse==admse_evaluation)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031evaluation:(void*)location030evaluation;
      mypath->_callbackname=(mypath->_keeplist)?"location031evaluation":"location030evaluation";
    }
    else if(mypath->_text->_admse==admse_lexval)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031lexval:(void*)location030lexval;
      mypath->_callbackname=(mypath->_keeplist)?"location031lexval":"location030lexval";
    }
    else if(mypath->_text->_admse==admse_type)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031type:(void*)location030type;
      mypath->_callbackname=(mypath->_keeplist)?"location031type":"location030type";
    }
    else if(mypath->_text->_admse==admse_tree)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031tree:(void*)location030tree;
      mypath->_callbackname=(mypath->_keeplist)?"location031tree":"location030tree";
    }
    else if(mypath->_text->_admse==admse_direction)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031direction:(void*)location030direction;
      mypath->_callbackname=(mypath->_keeplist)?"location031direction":"location030direction";
    }
    else if(mypath->_text->_admse==admse_grounded)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031grounded:(void*)location030grounded;
      mypath->_callbackname=(mypath->_keeplist)?"location031grounded":"location030grounded";
    }
    else if(mypath->_text->_admse==admse_location)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031location:(void*)location030location;
      mypath->_callbackname=(mypath->_keeplist)?"location031location":"location030location";
    }
    else if(mypath->_text->_admse==admse_pnode)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031pnode:(void*)location030pnode;
      mypath->_callbackname=(mypath->_keeplist)?"location031pnode":"location030pnode";
    }
    else if(mypath->_text->_admse==admse_nnode)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031nnode:(void*)location030nnode;
      mypath->_callbackname=(mypath->_keeplist)?"location031nnode":"location030nnode";
    }
    else if(mypath->_text->_admse==admse_dependency)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031dependency:(void*)location030dependency;
      mypath->_callbackname=(mypath->_keeplist)?"location031dependency":"location030dependency";
    }
    else if(mypath->_text->_admse==admse_static)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031static:(void*)location030static;
      mypath->_callbackname=(mypath->_keeplist)?"location031static":"location030static";
    }
    else if(mypath->_text->_admse==admse_dynamic)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031dynamic:(void*)location030dynamic;
      mypath->_callbackname=(mypath->_keeplist)?"location031dynamic":"location030dynamic";
    }
    else if(mypath->_text->_admse==admse_sizetype)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031sizetype:(void*)location030sizetype;
      mypath->_callbackname=(mypath->_keeplist)?"location031sizetype":"location030sizetype";
    }
    else if(mypath->_text->_admse==admse_parametertype)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031parametertype:(void*)location030parametertype;
      mypath->_callbackname=(mypath->_keeplist)?"location031parametertype":"location030parametertype";
    }
    else if(mypath->_text->_admse==admse_maxsize)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031maxsize:(void*)location030maxsize;
      mypath->_callbackname=(mypath->_keeplist)?"location031maxsize":"location030maxsize";
    }
    else if(mypath->_text->_admse==admse_minsize)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031minsize:(void*)location030minsize;
      mypath->_callbackname=(mypath->_keeplist)?"location031minsize":"location030minsize";
    }
    else if(mypath->_text->_admse==admse_input)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031input:(void*)location030input;
      mypath->_callbackname=(mypath->_keeplist)?"location031input":"location030input";
    }
    else if(mypath->_text->_admse==admse_output)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031output:(void*)location030output;
      mypath->_callbackname=(mypath->_keeplist)?"location031output":"location030output";
    }
    else if(mypath->_text->_admse==admse_scope)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031scope:(void*)location030scope;
      mypath->_callbackname=(mypath->_keeplist)?"location031scope":"location030scope";
    }
    else if(mypath->_text->_admse==admse_default)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031default:(void*)location030default;
      mypath->_callbackname=(mypath->_keeplist)?"location031default":"location030default";
    }
    else if(mypath->_text->_admse==admse_derivate)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031derivate:(void*)location030derivate;
      mypath->_callbackname=(mypath->_keeplist)?"location031derivate":"location030derivate";
    }
    else if(mypath->_text->_admse==admse_isstate)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031isstate:(void*)location030isstate;
      mypath->_callbackname=(mypath->_keeplist)?"location031isstate":"location030isstate";
    }
    else if(mypath->_text->_admse==admse_usedinmodel)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031usedinmodel:(void*)location030usedinmodel;
      mypath->_callbackname=(mypath->_keeplist)?"location031usedinmodel":"location030usedinmodel";
    }
    else if(mypath->_text->_admse==admse_usedininstance)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031usedininstance:(void*)location030usedininstance;
      mypath->_callbackname=(mypath->_keeplist)?"location031usedininstance":"location030usedininstance";
    }
    else if(mypath->_text->_admse==admse_usedininitial_step)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031usedininitial_step:(void*)location030usedininitial_step;
      mypath->_callbackname=(mypath->_keeplist)?"location031usedininitial_step":"location030usedininitial_step";
    }
    else if(mypath->_text->_admse==admse_usedinevaluate)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031usedinevaluate:(void*)location030usedinevaluate;
      mypath->_callbackname=(mypath->_keeplist)?"location031usedinevaluate":"location030usedinevaluate";
    }
    else if(mypath->_text->_admse==admse_usedinnoise)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031usedinnoise:(void*)location030usedinnoise;
      mypath->_callbackname=(mypath->_keeplist)?"location031usedinnoise":"location030usedinnoise";
    }
    else if(mypath->_text->_admse==admse_usedinfinal)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031usedinfinal:(void*)location030usedinfinal;
      mypath->_callbackname=(mypath->_keeplist)?"location031usedinfinal":"location030usedinfinal";
    }
    else if(mypath->_text->_admse==admse_setinmodel)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031setinmodel:(void*)location030setinmodel;
      mypath->_callbackname=(mypath->_keeplist)?"location031setinmodel":"location030setinmodel";
    }
    else if(mypath->_text->_admse==admse_setininstance)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031setininstance:(void*)location030setininstance;
      mypath->_callbackname=(mypath->_keeplist)?"location031setininstance":"location030setininstance";
    }
    else if(mypath->_text->_admse==admse_setininitial_step)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031setininitial_step:(void*)location030setininitial_step;
      mypath->_callbackname=(mypath->_keeplist)?"location031setininitial_step":"location030setininitial_step";
    }
    else if(mypath->_text->_admse==admse_setinevaluate)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031setinevaluate:(void*)location030setinevaluate;
      mypath->_callbackname=(mypath->_keeplist)?"location031setinevaluate":"location030setinevaluate";
    }
    else if(mypath->_text->_admse==admse_setinnoise)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031setinnoise:(void*)location030setinnoise;
      mypath->_callbackname=(mypath->_keeplist)?"location031setinnoise":"location030setinnoise";
    }
    else if(mypath->_text->_admse==admse_setinfinal)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031setinfinal:(void*)location030setinfinal;
      mypath->_callbackname=(mypath->_keeplist)?"location031setinfinal":"location030setinfinal";
    }
    else if(mypath->_text->_admse==admse_setingetprev)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031setingetprev:(void*)location030setingetprev;
      mypath->_callbackname=(mypath->_keeplist)?"location031setingetprev":"location030setingetprev";
    }
    else if(mypath->_text->_admse==admse_TemperatureDependent)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031TemperatureDependent:(void*)location030TemperatureDependent;
      mypath->_callbackname=(mypath->_keeplist)?"location031TemperatureDependent":"location030TemperatureDependent";
    }
    else if(mypath->_text->_admse==admse_OPdependent)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031OPdependent:(void*)location030OPdependent;
      mypath->_callbackname=(mypath->_keeplist)?"location031OPdependent":"location030OPdependent";
    }
    else if(mypath->_text->_admse==admse_insource)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031insource:(void*)location030insource;
      mypath->_callbackname=(mypath->_keeplist)?"location031insource":"location030insource";
    }
    else if(mypath->_text->_admse==admse_vcount)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031vcount:(void*)location030vcount;
      mypath->_callbackname=(mypath->_keeplist)?"location031vcount":"location030vcount";
    }
    else if(mypath->_text->_admse==admse_vlast)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031vlast:(void*)location030vlast;
      mypath->_callbackname=(mypath->_keeplist)?"location031vlast":"location030vlast";
    }
    else if(mypath->_text->_admse==admse_arraydefault)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031arraydefault:(void*)location030arraydefault;
      mypath->_callbackname=(mypath->_keeplist)?"location031arraydefault":"location030arraydefault";
    }
    else if(mypath->_text->_admse==admse_alias)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031alias:(void*)location030alias;
      mypath->_callbackname=(mypath->_keeplist)?"location031alias":"location030alias";
    }
    else if(mypath->_text->_admse==admse_ddxprobe)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031ddxprobe:(void*)location030ddxprobe;
      mypath->_callbackname=(mypath->_keeplist)?"location031ddxprobe":"location030ddxprobe";
    }
    else if(mypath->_text->_admse==admse_whitenoise)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031whitenoise:(void*)location030whitenoise;
      mypath->_callbackname=(mypath->_keeplist)?"location031whitenoise":"location030whitenoise";
    }
    else if(mypath->_text->_admse==admse_flickernoise)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031flickernoise:(void*)location030flickernoise;
      mypath->_callbackname=(mypath->_keeplist)?"location031flickernoise":"location030flickernoise";
    }
    else if(mypath->_text->_admse==admse_switch)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031switch:(void*)location030switch;
      mypath->_callbackname=(mypath->_keeplist)?"location031switch":"location030switch";
    }
    else if(mypath->_text->_admse==admse_infexpr)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031infexpr:(void*)location030infexpr;
      mypath->_callbackname=(mypath->_keeplist)?"location031infexpr":"location030infexpr";
    }
    else if(mypath->_text->_admse==admse_supexpr)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031supexpr:(void*)location030supexpr;
      mypath->_callbackname=(mypath->_keeplist)?"location031supexpr":"location030supexpr";
    }
    else if(mypath->_text->_admse==admse_infboundtype)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031infboundtype:(void*)location030infboundtype;
      mypath->_callbackname=(mypath->_keeplist)?"location031infboundtype":"location030infboundtype";
    }
    else if(mypath->_text->_admse==admse_supboundtype)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031supboundtype:(void*)location030supboundtype;
      mypath->_callbackname=(mypath->_keeplist)?"location031supboundtype":"location030supboundtype";
    }
    else if(mypath->_text->_admse==admse_row)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031row:(void*)location030row;
      mypath->_callbackname=(mypath->_keeplist)?"location031row":"location030row";
    }
    else if(mypath->_text->_admse==admse_column)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031column:(void*)location030column;
      mypath->_callbackname=(mypath->_keeplist)?"location031column":"location030column";
    }
    else if(mypath->_text->_admse==admse_diagonal)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031diagonal:(void*)location030diagonal;
      mypath->_callbackname=(mypath->_keeplist)?"location031diagonal":"location030diagonal";
    }
    else if(mypath->_text->_admse==admse_code)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031code:(void*)location030code;
      mypath->_callbackname=(mypath->_keeplist)?"location031code":"location030code";
    }
    else if(mypath->_text->_admse==admse_value)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031value:(void*)location030value;
      mypath->_callbackname=(mypath->_keeplist)?"location031value":"location030value";
    }
    else if(mypath->_text->_admse==admse_math)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031math:(void*)location030math;
      mypath->_callbackname=(mypath->_keeplist)?"location031math":"location030math";
    }
    else if(mypath->_text->_admse==admse_subexpression)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031subexpression:(void*)location030subexpression;
      mypath->_callbackname=(mypath->_keeplist)?"location031subexpression":"location030subexpression";
    }
    else if(mypath->_text->_admse==admse_arg1)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031arg1:(void*)location030arg1;
      mypath->_callbackname=(mypath->_keeplist)?"location031arg1":"location030arg1";
    }
    else if(mypath->_text->_admse==admse_arg2)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031arg2:(void*)location030arg2;
      mypath->_callbackname=(mypath->_keeplist)?"location031arg2":"location030arg2";
    }
    else if(mypath->_text->_admse==admse_arg3)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031arg3:(void*)location030arg3;
      mypath->_callbackname=(mypath->_keeplist)?"location031arg3":"location030arg3";
    }
    else if(mypath->_text->_admse==admse_scalingunit)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031scalingunit:(void*)location030scalingunit;
      mypath->_callbackname=(mypath->_keeplist)?"location031scalingunit":"location030scalingunit";
    }
    else if(mypath->_text->_admse==admse_cast)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031cast:(void*)location030cast;
      mypath->_callbackname=(mypath->_keeplist)?"location031cast":"location030cast";
    }
    else if(mypath->_text->_admse==admse_unique_id)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031unique_id:(void*)location030unique_id;
      mypath->_callbackname=(mypath->_keeplist)?"location031unique_id":"location030unique_id";
    }
    else if(mypath->_text->_admse==admse_definition)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031definition:(void*)location030definition;
      mypath->_callbackname=(mypath->_keeplist)?"location031definition":"location030definition";
    }
    else if(mypath->_text->_admse==admse_class)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031class:(void*)location030class;
      mypath->_callbackname=(mypath->_keeplist)?"location031class":"location030class";
    }
    else if(mypath->_text->_admse==admse_arguments)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031arguments:(void*)location030arguments;
      mypath->_callbackname=(mypath->_keeplist)?"location031arguments":"location030arguments";
    }
    else if(mypath->_text->_admse==admse_prototype)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031prototype:(void*)location030prototype;
      mypath->_callbackname=(mypath->_keeplist)?"location031prototype":"location030prototype";
    }
    else if(mypath->_text->_admse==admse_index)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031index:(void*)location030index;
      mypath->_callbackname=(mypath->_keeplist)?"location031index":"location030index";
    }
    else if(mypath->_text->_admse==admse_seen)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031seen:(void*)location030seen;
      mypath->_callbackname=(mypath->_keeplist)?"location031seen":"location030seen";
    }
    else if(mypath->_text->_admse==admse_hasspecialnumber)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031hasspecialnumber:(void*)location030hasspecialnumber;
      mypath->_callbackname=(mypath->_keeplist)?"location031hasspecialnumber":"location030hasspecialnumber";
    }
    else if(mypath->_text->_admse==admse_hasVoltageDependentFunction)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031hasVoltageDependentFunction:(void*)location030hasVoltageDependentFunction;
      mypath->_callbackname=(mypath->_keeplist)?"location031hasVoltageDependentFunction":"location030hasVoltageDependentFunction";
    }
    else if(mypath->_text->_admse==admse_infinity)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031infinity:(void*)location030infinity;
      mypath->_callbackname=(mypath->_keeplist)?"location031infinity":"location030infinity";
    }
    else if(mypath->_text->_admse==admse_function)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031function:(void*)location030function;
      mypath->_callbackname=(mypath->_keeplist)?"location031function":"location030function";
    }
    else if(mypath->_text->_admse==admse_terminal)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031terminal:(void*)location030terminal;
      mypath->_callbackname=(mypath->_keeplist)?"location031terminal":"location030terminal";
    }
    else if(mypath->_text->_admse==admse_parameterset)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031parameterset:(void*)location030parameterset;
      mypath->_callbackname=(mypath->_keeplist)?"location031parameterset":"location030parameterset";
    }
    else if(mypath->_text->_admse==admse_parameter)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031parameter:(void*)location030parameter;
      mypath->_callbackname=(mypath->_keeplist)?"location031parameter":"location030parameter";
    }
    else if(mypath->_text->_admse==admse_nodefrominstantiator)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031nodefrominstantiator:(void*)location030nodefrominstantiator;
      mypath->_callbackname=(mypath->_keeplist)?"location031nodefrominstantiator":"location030nodefrominstantiator";
    }
    else if(mypath->_text->_admse==admse_nodefrommodule)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031nodefrommodule:(void*)location030nodefrommodule;
      mypath->_callbackname=(mypath->_keeplist)?"location031nodefrommodule":"location030nodefrommodule";
    }
    else if(mypath->_text->_admse==admse_lhs)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031lhs:(void*)location030lhs;
      mypath->_callbackname=(mypath->_keeplist)?"location031lhs":"location030lhs";
    }
    else if(mypath->_text->_admse==admse_rhs)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031rhs:(void*)location030rhs;
      mypath->_callbackname=(mypath->_keeplist)?"location031rhs":"location030rhs";
    }
    else if(mypath->_text->_admse==admse_if)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031if:(void*)location030if;
      mypath->_callbackname=(mypath->_keeplist)?"location031if":"location030if";
    }
    else if(mypath->_text->_admse==admse_then)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031then:(void*)location030then;
      mypath->_callbackname=(mypath->_keeplist)?"location031then":"location030then";
    }
    else if(mypath->_text->_admse==admse_else)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031else:(void*)location030else;
      mypath->_callbackname=(mypath->_keeplist)?"location031else":"location030else";
    }
    else if(mypath->_text->_admse==admse_initial)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031initial:(void*)location030initial;
      mypath->_callbackname=(mypath->_keeplist)?"location031initial":"location030initial";
    }
    else if(mypath->_text->_admse==admse_condition)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031condition:(void*)location030condition;
      mypath->_callbackname=(mypath->_keeplist)?"location031condition":"location030condition";
    }
    else if(mypath->_text->_admse==admse_update)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031update:(void*)location030update;
      mypath->_callbackname=(mypath->_keeplist)?"location031update":"location030update";
    }
    else if(mypath->_text->_admse==admse_forblock)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031forblock:(void*)location030forblock;
      mypath->_callbackname=(mypath->_keeplist)?"location031forblock":"location030forblock";
    }
    else if(mypath->_text->_admse==admse_while)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031while:(void*)location030while;
      mypath->_callbackname=(mypath->_keeplist)?"location031while":"location030while";
    }
    else if(mypath->_text->_admse==admse_whileblock)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031whileblock:(void*)location030whileblock;
      mypath->_callbackname=(mypath->_keeplist)?"location031whileblock":"location030whileblock";
    }
    else if(mypath->_text->_admse==admse_caseitem)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031caseitem:(void*)location030caseitem;
      mypath->_callbackname=(mypath->_keeplist)?"location031caseitem":"location030caseitem";
    }
    else if(mypath->_text->_admse==admse_defaultcase)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031defaultcase:(void*)location030defaultcase;
      mypath->_callbackname=(mypath->_keeplist)?"location031defaultcase":"location030defaultcase";
    }
    else if(mypath->_text->_admse==admse_string)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031string:(void*)location030string;
      mypath->_callbackname=(mypath->_keeplist)?"location031string":"location030string";
    }
    else if(mypath->_text->_admse==admse_f)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031f:(void*)location030f;
      mypath->_callbackname=(mypath->_keeplist)?"location031f":"location030f";
    }
    else if(mypath->_text->_admse==admse_l)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031l:(void*)location030l;
      mypath->_callbackname=(mypath->_keeplist)?"location031l":"location030l";
    }
    else if(mypath->_text->_admse==admse_c)
    {
      mypath->_callback=(mypath->_keeplist)?(void*)location031c:(void*)location030c;
      mypath->_callbackname=(mypath->_keeplist)?"location031c":"location030c";
    }
    else
    {
      adms_message_fatal_continue(("element or attribute '%s' does not exist\n",mypath->_text->_value))
      adms_message_fatal(("see %s\n",adms_transform_uid(mypath->_transform)))
    }
  }
}
static void postpath (p_path mypath)
{
  p_slist l;
  if(mypath->_callback==(void*)location02)
  {
    const char* match=((p_admst)mypath->_text->_token->data)->_item.s;
    if(!(mypath->_template=lookfortemplates(mypath->_transform,match)))
    {
      adms_message_fatal_continue(("Template not found: %s\n",match))
      adms_message_fatal(("  see:  %s\n",adms_transform_uid(mypath->_transform)))
    }
  }
  for(l=mypath->_bar;l;l=l->next)
  {
    p_slist paths=(p_slist)l->data;
    for(;paths;paths=paths->next)
    {
      postpath((p_path)paths->data);
      attributecallback(mypath,l,paths);
    }
  }
  for(l=mypath->_arg;l;l=l->next)
  {
    p_slist paths=(p_slist)l->data;
    for(;paths;paths=paths->next)
    {
      postpath((p_path)paths->data);
      attributecallback(mypath,l,paths);
    }
  }
  for(l=mypath->_u;l;l=l->next)
    postpath((p_path)l->data);
  for(l=mypath->_b;l;l=l->next)
    postpath((p_path)l->data);
  for(l=mypath->_c;l;l=l->next)
    postpath((p_path)l->data);
  if(mypath->_text)
    posttext(mypath->_text);
}

static void location00 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newpn(dot->_previous,dot->_previouspath,dot);
  d->_position=dot->_position;
  d->_count=dot->_count;
  if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;;
}
static void location01 (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_admst d=adms_admst_newpn(dot->_previouspath->_previous,dot->_previouspath->_previouspath,dot->_previouspath);
  d->_position=dot->_previouspath->_position;
  d->_count=dot->_previouspath->_count;
  if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;;
}
typedef p_slist (*_p_cblocation) (p_ptraverse p,p_path mypath,p_admst dot);
typedef int (*_p_cbcondition) (const p_path mypath,p_admst myadmst);

void free_ptraverse (p_ptraverse p)
{
  p_slist l;
  p_slist ll;
  for(l=p->_alladmst;l;l=l->next)
    for(ll=(p_slist)l->data;ll;ll=ll->next)
      deref((p_admst)ll->data);
  for(l=p->_aliasadmst;l;l=l->next)
    deref((p_admst)l->data);
  for(l=p->_admst;l;l=l->next)
    deref((p_admst)l->data);
  adms_slist_free(p->_alladmst);
  adms_slist_free(p->_aliasadmst);
  adms_slist_free(p->_admst);
  free(p);
}
static p_slist slash (p_ptraverse p,p_slist paths,p_admst dot)
{
  p_slist output=NULL;
  int premier=1;
  adms_slist_push(&output,(p_adms)dot);
  for(;paths;paths=paths->next)
  {
    p_slist l;
    p_path mypath=(p_path)paths->data;
    p_slist output1=NULL;
    int dernier=(paths->next==NULL);
    if(mypath->_callback==(void*)groupage)
    {
      int count=0;
      for(l=output;l;l=l->next)
        if((((p_admst)l->data)->_selected==admse_yes)&&((p_admst)l->data)->_pseudo!=admse_empty)
        {
          p_ptraverse p0=bar((p_admst)l->data,mypath);
          adms_slist_concat(&output1,p0->_admst);
          adms_slist_free(p0->_alladmst);
          free(p0);
        }
      for(l=output1;l;l=l->next)
        ((p_admst)l->data)->_position=++count;
      p->_position=count;
    }
    else
    {
      p_admst ai;
      p->_position=0;
      p->_a1=p->_an=NULL;
      for(l=output;l;l=l->next)
        if((((p_admst)l->data)->_selected==admse_yes)&&((p_admst)l->data)->_pseudo!=admse_empty)
          ((_p_cblocation)mypath->_callback)(p,mypath,(p_admst)l->data);
      for(ai=p->_an;ai;ai=ai->_preva)
        adms_slist_push(&output1,(p_adms)ai);
    }
    if(premier)
      adms_slist_free(output),premier=0;
    if(!dernier)
      adms_slist_push(&p->_alladmst,(p_adms)output1);
    if((mypath->_callback!=(void*)location00)&&(mypath->_callback!=(void*)location01))
      for(l=output1;l;l=l->next)
        ((p_admst)l->data)->_count=p->_position;
    if(mypath->_c)
    {
      int count=0;
      for(l=output1;l;l=l->next)
        if(((_p_cbcondition)((p_path)mypath->_c->data)->_callback)((p_path)mypath->_c->data,(p_admst)l->data))
        {
          count++;
          if((mypath->_callback!=(void*)location00)&&(mypath->_callback!=(void*)location01))
            ((p_admst)l->data)->_position=count;
        }
        else
          ((p_admst)l->data)->_selected=admse_no;
      if((mypath->_callback!=(void*)location00)&&(mypath->_callback!=(void*)location01))
        for(l=output1;l;l=l->next)
          ((p_admst)l->data)->_count=count;
      if(dernier)
      {
        p_slist l=output1;
        p_slist n;
        p_slist lastnode=NULL;
        output1=NULL;
        for(;l;l=n)
          if(((p_admst)l->data)->_selected==admse_yes)
          {
            if(lastnode)
              lastnode->next=l,lastnode=l;
            else
              output1=lastnode=l;
            n=l->next;
          }
          else
            n=l->next,deref((p_admst)l->data),free(l);
        if(lastnode)
          lastnode->next=NULL;
      }
    }
    output=output1;
  }
  return output;
}
p_ptraverse bar (p_admst dot,p_path mypath)
{
  p_ptraverse p=adms_ptraverse_new(mypath->_transform);
  p_slist bars;
  p_slist output=NULL;
  for(bars=mypath->_bar;bars;bars=bars->next)
    adms_slist_concat(&output,slash(p,(p_slist)bars->data,dot));
  p->_admst=output;
  return p;
}
static void addptraverse (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist paths0=(p_slist)mypath->_arg->data;
  p_slist paths1=(p_slist)mypath->_arg->next->data;
  p_ptraverse p0=adms_ptraverse_new(mypath->_transform);
  p_slist o0=slash(p0,paths0,dot);
  p_ptraverse p1=adms_ptraverse_new(mypath->_transform);
  p_slist o1=slash(p1,paths1,dot);
  for(;o0&&o1;o0=o0->next,o1=o1->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    p_admst myadmst1=(p_admst)o1->data;
    admse mytype0=myadmst0->_pseudo;
    admse mytype1=myadmst1->_pseudo;
    if((mytype0==admse_basicinteger)&&(mytype1==admse_basicinteger))
    {
      p_admst d=adms_admst_newbi(dot,dot,myadmst0->_item.i+myadmst1->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if((mytype0==admse_basicreal)&&(mytype1==admse_basicreal))
    {
      p_admst d=adms_admst_newbr(dot,dot,myadmst0->_item.r+myadmst1->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,strtod(aprintf(mypath->_transform,myadmst0),NULL)+strtod(aprintf(mypath->_transform,myadmst1),NULL));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  for(o0=o1?o1:o0;o0;o0=o0->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    admse mytype0=myadmst0->_pseudo;
    if(mytype0==admse_basicinteger)
    {
      p_admst d=adms_admst_newbi(dot,dot,myadmst0->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if(mytype0==admse_basicreal)
    {
      p_admst d=adms_admst_newbr(dot,dot,myadmst0->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,strtod(aprintf(mypath->_transform,myadmst0),NULL));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
}
static void addmtraverse (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist paths0=(p_slist)mypath->_arg->data;
  p_slist paths1=(p_slist)mypath->_arg->next->data;
  p_ptraverse p0=adms_ptraverse_new(mypath->_transform);
  p_slist o0=slash(p0,paths0,dot);
  p_ptraverse p1=adms_ptraverse_new(mypath->_transform);
  p_slist o1=slash(p1,paths1,dot);
  for(;o0&&o1;o0=o0->next,o1=o1->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    p_admst myadmst1=(p_admst)o1->data;
    admse mytype0=myadmst0->_pseudo;
    admse mytype1=myadmst1->_pseudo;
    if((mytype0==admse_basicinteger)&&(mytype1==admse_basicinteger))
    {
      p_admst d=adms_admst_newbi(dot,dot,myadmst0->_item.i-myadmst1->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if((mytype0==admse_basicreal)&&(mytype1==admse_basicreal))
    {
      p_admst d=adms_admst_newbr(dot,dot,myadmst0->_item.r-myadmst1->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,strtod(aprintf(mypath->_transform,myadmst0),NULL)-strtod(aprintf(mypath->_transform,myadmst1),NULL));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  for(;o0;o0=o0->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    admse mytype0=myadmst0->_pseudo;
    if(mytype0==admse_basicinteger)
    {
      p_admst d=adms_admst_newbi(dot,dot,myadmst0->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if(mytype0==admse_basicreal)
    {
      p_admst d=adms_admst_newbr(dot,dot,myadmst0->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,strtod(aprintf(mypath->_transform,myadmst0),NULL));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  for(;o1;o1=o1->next)
  {
    p_admst myadmst1=(p_admst)o1->data;
    admse mytype1=myadmst1->_pseudo;
    if(mytype1==admse_basicinteger)
    {
      p_admst d=adms_admst_newbi(dot,dot,-myadmst1->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if(mytype1==admse_basicreal)
    {
      p_admst d=adms_admst_newbr(dot,dot,-myadmst1->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,-1*strtod(aprintf(mypath->_transform,myadmst1),NULL));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
}
static void multtimetraverse (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist paths0=(p_slist)mypath->_arg->data;
  p_slist paths1=(p_slist)mypath->_arg->next->data;
  p_ptraverse p0=adms_ptraverse_new(mypath->_transform);
  p_slist o0=slash(p0,paths0,dot);
  p_ptraverse p1=adms_ptraverse_new(mypath->_transform);
  p_slist o1=slash(p1,paths1,dot);
  for(;o0&&o1;o0=o0->next,o1=o1->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    p_admst myadmst1=(p_admst)o1->data;
    admse mytype0=myadmst0->_pseudo;
    admse mytype1=myadmst1->_pseudo;
    if((mytype0==admse_basicinteger)&&(mytype1==admse_basicinteger))
    {
      p_admst d=adms_admst_newbi(dot,dot,myadmst0->_item.i*myadmst1->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if((mytype0==admse_basicreal)&&(mytype1==admse_basicreal))
    {
      p_admst d=adms_admst_newbr(dot,dot,myadmst0->_item.r*myadmst1->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,strtod(aprintf(mypath->_transform,myadmst0),NULL)*strtod(aprintf(mypath->_transform,myadmst1),NULL));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  for(o0=o1?o1:o0;o0;o0=o0->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    admse mytype0=myadmst0->_pseudo;
    if(mytype0==admse_basicinteger)
    {
      p_admst d=adms_admst_newbi(dot,dot,myadmst0->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if(mytype0==admse_basicreal)
    {
      p_admst d=adms_admst_newbr(dot,dot,myadmst0->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,strtod(aprintf(mypath->_transform,myadmst0),NULL));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
}
static void multdivtraverse (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist paths0=(p_slist)mypath->_arg->data;
  p_slist paths1=(p_slist)mypath->_arg->next->data;
  p_ptraverse p0=adms_ptraverse_new(mypath->_transform);
  p_slist o0=slash(p0,paths0,dot);
  p_ptraverse p1=adms_ptraverse_new(mypath->_transform);
  p_slist o1=slash(p1,paths1,dot);
  for(;o0&&o1;o0=o0->next,o1=o1->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    p_admst myadmst1=(p_admst)o1->data;
    admse mytype0=myadmst0->_pseudo;
    admse mytype1=myadmst1->_pseudo;
    if((mytype0==admse_basicinteger)&&(mytype1==admse_basicinteger))
    {
      p_admst d=adms_admst_newbr(dot,dot,(double)myadmst0->_item.i/(double)myadmst1->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if((mytype0==admse_basicreal)&&(mytype1==admse_basicreal))
    {
      p_admst d=adms_admst_newbr(dot,dot,myadmst0->_item.r/myadmst1->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,(strtod(aprintf(mypath->_transform,myadmst0),NULL)/strtod(aprintf(mypath->_transform,myadmst1),NULL)));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  for(;o0;o0=o0->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    admse mytype0=myadmst0->_pseudo;
    if(mytype0==admse_basicinteger)
    {
      p_admst d=adms_admst_newbr(dot,dot,(double)myadmst0->_item.i/1.0);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if(mytype0==admse_basicreal)
    {
      p_admst d=adms_admst_newbr(dot,dot,myadmst0->_item.r/1.0);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,strtod(aprintf(mypath->_transform,myadmst0),NULL)/1.0);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
  for(;o1;o1=o1->next)
  {
    p_admst myadmst1=(p_admst)o1->data;
    admse mytype1=myadmst1->_pseudo;
    if(mytype1==admse_basicinteger)
    {
      p_admst d=adms_admst_newbr(dot,dot,1.0/(double)myadmst1->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if(mytype1==admse_basicreal)
    {
      p_admst d=adms_admst_newbr(dot,dot,1.0/myadmst1->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,1.0/strtod(aprintf(mypath->_transform,myadmst1),NULL));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
}
static void unaryptraverse (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist paths0=(p_slist)mypath->_arg->data;
  p_ptraverse p0=adms_ptraverse_new(mypath->_transform);
  p_slist o0=slash(p0,paths0,dot);
  for(;o0;o0=o0->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    admse mytype0=myadmst0->_pseudo;
    if(mytype0==admse_basicinteger)
    {
      p_admst d=adms_admst_newbi(dot,dot,+myadmst0->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if(mytype0==admse_basicreal)
    {
      p_admst d=adms_admst_newbr(dot,dot,+myadmst0->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,+strtod(aprintf(mypath->_transform,myadmst0),NULL));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
}
static void unarymtraverse (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist paths0=(p_slist)mypath->_arg->data;
  p_ptraverse p0=adms_ptraverse_new(mypath->_transform);
  p_slist o0=slash(p0,paths0,dot);
  for(;o0;o0=o0->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    admse mytype0=myadmst0->_pseudo;
    if(mytype0==admse_basicinteger)
    {
      p_admst d=adms_admst_newbi(dot,dot,-myadmst0->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else if(mytype0==admse_basicreal)
    {
      p_admst d=adms_admst_newbr(dot,dot,-myadmst0->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
    else
    { // Convert the string representation to a number
      p_admst d=adms_admst_newbr(dot,dot,-strtod(aprintf(mypath->_transform,myadmst0),NULL));if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
    }
  }
}
static void incrptraverse (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist paths0=(p_slist)mypath->_arg->data;
  p_ptraverse p0=adms_ptraverse_new(mypath->_transform);
  p_slist o0=slash(p0,paths0,dot);
  for(;o0;o0=o0->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    admse mytype0=myadmst0->_pseudo;
    if(mytype0==admse_basiclist)
    {
      p_slist dollarlist=((p_admstvariable)myadmst0->_item.p)->_value;
      for(;dollarlist;dollarlist=dollarlist->next)
      {
        p_admst myadmst1=(p_admst)dollarlist->data;
        admse mytype1=myadmst1->_pseudo;
        if(mytype1==admse_basicinteger)
        {
          p_admst d=adms_admst_newbi(dot,dot,myadmst1->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
          myadmst1->_item.i+=1;
        }
        else if(mytype1==admse_basicreal)
        {
          p_admst d=adms_admst_newbr(dot,dot,myadmst1->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
          myadmst1->_item.r+=1.0;
        }
        else
          adms_message_fatal(("%s: '++' operator - case not implemented - sorry!\n",adms_transform_uid(mypath->_transform)))
      }
    }
  }
}
static void incrmtraverse (p_ptraverse p,p_path mypath,p_admst dot)
{
  p_slist paths0=(p_slist)mypath->_arg->data;
  p_ptraverse p0=adms_ptraverse_new(mypath->_transform);
  p_slist o0=slash(p0,paths0,dot);
  for(;o0;o0=o0->next)
  {
    p_admst myadmst0=(p_admst)o0->data;
    admse mytype0=myadmst0->_pseudo;
    if(mytype0==admse_basiclist)
    {
      p_slist dollarlist=((p_admstvariable)myadmst0->_item.p)->_value;
      for(;dollarlist;dollarlist=dollarlist->next)
      {
        p_admst myadmst1=(p_admst)dollarlist->data;
        admse mytype1=myadmst1->_pseudo;
        if(mytype1==admse_basicinteger)
        {
          p_admst d=adms_admst_newbi(dot,dot,myadmst1->_item.i);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
          myadmst1->_item.i-=1;
        }
        else if(mytype1==admse_basicreal)
        {
          p_admst d=adms_admst_newbr(dot,dot,myadmst1->_item.r);if(d->_preva) d->_preva->_nexta=d->_nexta,d->_preva=NULL; if(d->_nexta) d->_nexta->_preva=d->_preva,d->_nexta=NULL;if(p->_a1==NULL) p->_a1=p->_an=d; else p->_an->_nexta=d,d->_preva=p->_an,p->_an=d;d->_position=++p->_position;
          myadmst1->_item.r-=1.0;
        }
        else
          adms_message_fatal(("%s: '--' operator - case not implemented - sorry!\n",adms_transform_uid(mypath->_transform)))
      }
    }
  }
}
static int expression01 (const p_path mypath,p_admst dot)
{
  p_ptraverse p0=bar(dot,(p_path)mypath->_u->data);
  int pos=dot->_position;
  p_slist l;
  for(l=p0->_admst;l;l=l->next)
  {
    p_admst myadmst0=(p_admst)l->data;
    admse mytype0=myadmst0->_pseudo;
    if(mytype0==admse_basicinteger)
    {
      if(pos==myadmst0->_item.i)
      {
        free_ptraverse(p0);
        return 1;
      }
    }
    else
      adms_message_fatal(("%s: 'integer' expected!\n",adms_transform_uid(mypath->_transform)))
  }
  free_ptraverse(p0);
  return 0;
}

#define admstpatherror(mypparse,msgid) admstpatherrorimpl(mypparse,msgid)

#define ISPATH     ((int)(long)globalctxt->data==0)
#define ISTEXT     ((int)(long)globalctxt->data==1)
#define ISTIC      ((int)(long)globalctxt->data==2)
#define SETPATH    adms_slist_push(&globalctxt,(p_adms)0);
#define SETTEXT    adms_slist_push(&globalctxt,(p_adms)1);
#define SETTIC     adms_slist_push(&globalctxt,(p_adms)2);
#define PARENMATCH (parenidx&&paren==(int)(long)parenidx->data)
#define INSIDEPATH (globalctxt&&(globalctxt->next)&&(((int)(long)globalctxt->next->data)==0))

static p_slist globalctxt=NULL;
static int goto_atext=0;
static int paren=0;
static p_slist parenidx=NULL;
static int globalignorequote=0;

static p_path BASICSTRING (const p_pparse mypparse,char *mytvalue)
{
  p_path ret=adms_path_new(mypparse->_transform,adms_text_new(mypparse->_transform,mytvalue));
  adms_slist_push(&(ret->_text->_token),(p_adms)adms_admst_newks(mytvalue));
  ret->_text->_admse=ns_strtoe(((p_admst)ret->_text->_token->data)->_item.s);
  ret->_aname=adms_kclone(mytvalue);
  return ret;
}
static p_path BASICINTEGER (const p_pparse mypparse,char *mytvalue)
{
  p_path ret=adms_path_new(mypparse->_transform,adms_text_new(mypparse->_transform,mytvalue));
  adms_slist_push(&(ret->_text->_token),(p_adms)adms_admst_newbi(NULL,NULL,adms_strtol(mypparse->_transform,mytvalue)));
  ((p_admst)ret->_text->_token->data)->_refd=0;
  ret->_text->_admse=admse__any;
  ret->_aname=adms_kclone(mytvalue);
  return ret;
}

int is_admst (const char* name)
{
  return (((strlen(name)==5)&&!strncmp(name,"admst",5))||((strlen(name)>5)&&!strncmp(name,"admst:",6)));
}
void dbtext (p_text mytext)
{
  p_slist li;
  if(mytext->_aname)
    adms_message_admstdbg_impl("<text n=\"%s\" v=\"%s\" e=\"%s\">",mytext->_aname,mytext->_value,ns_etostr(mytext->_admse));
  else
    adms_message_admstdbg_impl("<text v=\"%s\" e=\"%s\">",mytext->_value,ns_etostr(mytext->_admse));
  for(li=mytext->_token;li;li=li->next)
  {
    p_adms mytoken=li->data;
    if(mytoken->_datatypename==admse_text && ((p_text)mytoken)->_admse==admse__s)
      adms_message_admstdbg_impl("<token t=\"special-%%s\" e=\"%s\"/>\n",ns_etostr(((p_text)mytoken)->_admse));
    else if(mytoken->_datatypename==admse_text)
      dbtext((p_text)mytoken);
    else if(mytoken->_datatypename==admse_admst)
    {
      adms_message_admstdbg_impl("<token t=\"admst\" pseudo=\"%s\">",ns_etostr(((p_admst)mytoken)->_pseudo));
      adms_message_admstdbg_impl("%s",aprintf(mytext->_transform,(p_admst)mytoken));
      adms_message_admstdbg_impl("</token>\n");
    }
    else if(mytoken->_datatypename==admse_path)
    {
      adms_message_admstdbg_impl("<token t=\"%%\">");
      dbpath((p_path)mytoken);
      adms_message_admstdbg_impl("</token>");
    }
  }
  if(mytext->_aname)
    adms_message_admstdbg_impl("</text>\n",mytext->_aname);
  else
    adms_message_admstdbg_impl("</text>\n");
}
void dbpath (p_path mypath)
{
  if(mypath->_text||mypath->_bar||mypath->_arg||mypath->_u||mypath->_b||mypath->_c)
  {
    adms_message_admstdbg_impl("<%s keeplist=\"%i\">",mypath->_callbackname,mypath->_keeplist);
    if(mypath->_bar)
    {
      p_slist bar;
      for(bar=mypath->_bar;bar;bar=bar->next)
      {
        p_slist l=(p_slist)bar->data;
        adms_message_admstdbg_impl("<bar>");
        for(;l;l=l->next)
          dbpath((p_path)l->data);
        adms_message_admstdbg_impl("</bar>");
      }
    }
    if(mypath->_arg)
    {
      p_slist arg;
      for(arg=mypath->_arg;arg;arg=arg->next)
      {
        p_slist l=(p_slist)arg->data;
        adms_message_admstdbg_impl("<arg>");
        for(;l;l=l->next)
          dbpath((p_path)l->data);
        adms_message_admstdbg_impl("</arg>");
      }
    }
    if(mypath->_u)
    {
      p_slist l;
      adms_message_admstdbg_impl("<u>");
      for(l=mypath->_u;l;l=l->next)
        dbpath((p_path)l->data);
      adms_message_admstdbg_impl("</u>");
    }
    if(mypath->_b)
    {
      p_slist l;
      adms_message_admstdbg_impl("<b>");
      for(l=mypath->_b;l;l=l->next)
        dbpath((p_path)l->data);
      adms_message_admstdbg_impl("</b>");
    }
    if(mypath->_c)
    {
      p_slist l;
      adms_message_admstdbg_impl("<c>");
      for(l=mypath->_c;l;l=l->next)
        dbpath((p_path)l->data);
      adms_message_admstdbg_impl("</c>");
    }
    if(mypath->_text)
      dbtext(mypath->_text);
    adms_message_admstdbg_impl("</%s>",mypath->_callbackname);
  }
  else
    adms_message_admstdbg_impl("<%s/>",mypath->_callbackname);
}

static int binaryand (const p_path mypath,p_admst myadmst)
{
  if(((_p_cbcondition)((p_path)mypath->_b->data)->_callback)((p_path)mypath->_b->data,myadmst))
    return ((_p_cbcondition)((p_path)mypath->_b->next->data)->_callback)((p_path)mypath->_b->next->data,myadmst);
  return 0;
}
static int binaryor (const p_path mypath,p_admst myadmst)
{
  if(!((_p_cbcondition)((p_path)mypath->_b->data)->_callback)((p_path)mypath->_b->data,myadmst))
    return ((_p_cbcondition)((p_path)mypath->_b->next->data)->_callback)((p_path)mypath->_b->next->data,myadmst);
  return 1;
}

static int atomicnilled (const p_path mypath,p_admst myadmst)
{
  p_admst myadmst0;
  p_ptraverse p0=bar(myadmst,(p_path)mypath->_u->data);
  int passed=(p0->_admst==NULL)||(p0->_admst->data==NULL)||((myadmst0=aread((p_admst)p0->_admst->data))==NULL)||(myadmst0->_item.p==NULL);
  free_ptraverse(p0);
  return passed;
}
static int atomicexists (const p_path mypath,p_admst myadmst)
{
  return !atomicnilled(mypath,myadmst);
}
static int atomicisdefault (const p_path mypath,p_admst myadmst)
{
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_nilled && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_nilled && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_assignment && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_assignment && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_contribution && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_contribution && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_conditional && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_conditional && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_forloop && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_forloop && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_whileloop && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_whileloop && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_case && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_case && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_blockvariable && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_blockvariable && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_block && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_block && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_callfunction && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_callfunction && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_name) return ((p_simulator)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_currentdate) return ((p_simulator)(myadmst->_item.p))->_currentdate_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_developer) return ((p_simulator)(myadmst->_item.p))->_developer_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_fullname) return ((p_simulator)(myadmst->_item.p))->_fullname_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_package_name) return ((p_simulator)(myadmst->_item.p))->_package_name_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_package_tarname) return ((p_simulator)(myadmst->_item.p))->_package_tarname_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_package_version) return ((p_simulator)(myadmst->_item.p))->_package_version_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_package_string) return ((p_simulator)(myadmst->_item.p))->_package_string_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_package_bugreport) return ((p_simulator)(myadmst->_item.p))->_package_bugreport_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_probe) return ((p_simulator)(myadmst->_item.p))->_probe_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_tmp) return ((p_simulator)(myadmst->_item.p))->_tmp_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_tmp1) return ((p_simulator)(myadmst->_item.p))->_tmp1_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_br1) return ((p_simulator)(myadmst->_item.p))->_br1_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_br2) return ((p_simulator)(myadmst->_item.p))->_br2_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_sr1) return ((p_simulator)(myadmst->_item.p))->_sr1_isdefault;
  if(myadmst->_pseudo==admse_simulator && mypath->_text->_admse==admse_ddx) return ((p_simulator)(myadmst->_item.p))->_ddx_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_name) return ((p_admsmain)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_argc) return ((p_admsmain)(myadmst->_item.p))->_argc_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_fullfilename) return ((p_admsmain)(myadmst->_item.p))->_fullfilename_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_filename) return ((p_admsmain)(myadmst->_item.p))->_filename_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_curfilename) return ((p_admsmain)(myadmst->_item.p))->_curfilename_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_curline) return ((p_admsmain)(myadmst->_item.p))->_curline_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_fpos) return ((p_admsmain)(myadmst->_item.p))->_fpos_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_simulator) return ((p_admsmain)(myadmst->_item.p))->_simulator_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_info) return ((p_admsmain)(myadmst->_item.p))->_info_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_usage) return ((p_admsmain)(myadmst->_item.p))->_usage_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_verbose) return ((p_admsmain)(myadmst->_item.p))->_verbose_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_hint) return ((p_admsmain)(myadmst->_item.p))->_hint_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_warning) return ((p_admsmain)(myadmst->_item.p))->_warning_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_obsolete) return ((p_admsmain)(myadmst->_item.p))->_obsolete_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_debug) return ((p_admsmain)(myadmst->_item.p))->_debug_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_dbg_vla) return ((p_admsmain)(myadmst->_item.p))->_dbg_vla_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_dbg_xml) return ((p_admsmain)(myadmst->_item.p))->_dbg_xml_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_error) return ((p_admsmain)(myadmst->_item.p))->_error_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_fatal) return ((p_admsmain)(myadmst->_item.p))->_fatal_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_dbg_mem) return ((p_admsmain)(myadmst->_item.p))->_dbg_mem_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_module) return ((p_admsmain)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_discipline) return ((p_admsmain)(myadmst->_item.p))->_discipline_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_nature) return ((p_admsmain)(myadmst->_item.p))->_nature_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_variable) return ((p_admsmain)(myadmst->_item.p))->_variable_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_argv) return ((p_admsmain)(myadmst->_item.p))->_argv_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_transform) return ((p_admsmain)(myadmst->_item.p))->_transform_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_invtransform) return ((p_admsmain)(myadmst->_item.p))->_invtransform_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_itransform) return ((p_admsmain)(myadmst->_item.p))->_itransform_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_itransforminsideapplytemplate) return ((p_admsmain)(myadmst->_item.p))->_itransforminsideapplytemplate_isdefault;
  if(myadmst->_pseudo==admse_admsmain && mypath->_text->_admse==admse_valueof) return ((p_admsmain)(myadmst->_item.p))->_valueof_isdefault;
  if(myadmst->_pseudo==admse_list && mypath->_text->_admse==admse_datatype) return ((p_list)(myadmst->_item.p))->_datatype_isdefault;
  if(myadmst->_pseudo==admse_list && mypath->_text->_admse==admse_item) return ((p_list)(myadmst->_item.p))->_item_isdefault;
  if(myadmst->_pseudo==admse_nature && mypath->_text->_admse==admse_access) return ((p_nature)(myadmst->_item.p))->_access_isdefault;
  if(myadmst->_pseudo==admse_nature && mypath->_text->_admse==admse_name) return ((p_nature)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_nature && mypath->_text->_admse==admse_abstol) return ((p_nature)(myadmst->_item.p))->_abstol_isdefault;
  if(myadmst->_pseudo==admse_nature && mypath->_text->_admse==admse_base) return ((p_nature)(myadmst->_item.p))->_base_isdefault;
  if(myadmst->_pseudo==admse_nature && mypath->_text->_admse==admse_ddt_name) return ((p_nature)(myadmst->_item.p))->_ddt_name_isdefault;
  if(myadmst->_pseudo==admse_nature && mypath->_text->_admse==admse_ddt_nature) return ((p_nature)(myadmst->_item.p))->_ddt_nature_isdefault;
  if(myadmst->_pseudo==admse_nature && mypath->_text->_admse==admse_idt_name) return ((p_nature)(myadmst->_item.p))->_idt_name_isdefault;
  if(myadmst->_pseudo==admse_nature && mypath->_text->_admse==admse_idt_nature) return ((p_nature)(myadmst->_item.p))->_idt_nature_isdefault;
  if(myadmst->_pseudo==admse_nature && mypath->_text->_admse==admse_units) return ((p_nature)(myadmst->_item.p))->_units_isdefault;
  if(myadmst->_pseudo==admse_discipline && mypath->_text->_admse==admse_name) return ((p_discipline)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_discipline && mypath->_text->_admse==admse_flow) return ((p_discipline)(myadmst->_item.p))->_flow_isdefault;
  if(myadmst->_pseudo==admse_discipline && mypath->_text->_admse==admse_potential) return ((p_discipline)(myadmst->_item.p))->_potential_isdefault;
  if(myadmst->_pseudo==admse_discipline && mypath->_text->_admse==admse_domain) return ((p_discipline)(myadmst->_item.p))->_domain_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_name) return ((p_module)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_node) return ((p_module)(myadmst->_item.p))->_node_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_nodealias) return ((p_module)(myadmst->_item.p))->_nodealias_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_branch) return ((p_module)(myadmst->_item.p))->_branch_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_branchalias) return ((p_module)(myadmst->_item.p))->_branchalias_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_analogfunction) return ((p_module)(myadmst->_item.p))->_analogfunction_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_instance) return ((p_module)(myadmst->_item.p))->_instance_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_variable) return ((p_module)(myadmst->_item.p))->_variable_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_analog) return ((p_module)(myadmst->_item.p))->_analog_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_block) return ((p_module)(myadmst->_item.p))->_block_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_blockvariable) return ((p_module)(myadmst->_item.p))->_blockvariable_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_assignment) return ((p_module)(myadmst->_item.p))->_assignment_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_callfunction) return ((p_module)(myadmst->_item.p))->_callfunction_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_contribution) return ((p_module)(myadmst->_item.p))->_contribution_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_conditional) return ((p_module)(myadmst->_item.p))->_conditional_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_case) return ((p_module)(myadmst->_item.p))->_case_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_forloop) return ((p_module)(myadmst->_item.p))->_forloop_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_whileloop) return ((p_module)(myadmst->_item.p))->_whileloop_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_instantiator) return ((p_module)(myadmst->_item.p))->_instantiator_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_expression) return ((p_module)(myadmst->_item.p))->_expression_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_jacobian) return ((p_module)(myadmst->_item.p))->_jacobian_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_probe) return ((p_module)(myadmst->_item.p))->_probe_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_source) return ((p_module)(myadmst->_item.p))->_source_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_range) return ((p_module)(myadmst->_item.p))->_range_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_attribute) return ((p_module)(myadmst->_item.p))->_attribute_isdefault;
  if(myadmst->_pseudo==admse_module && mypath->_text->_admse==admse_evaluation) return ((p_module)(myadmst->_item.p))->_evaluation_isdefault;
  if(myadmst->_pseudo==admse_analogfunction && mypath->_text->_admse==admse_module) return ((p_analogfunction)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_analogfunction && mypath->_text->_admse==admse_lexval) return ((p_analogfunction)(myadmst->_item.p))->_lexval_isdefault;
  if(myadmst->_pseudo==admse_analogfunction && mypath->_text->_admse==admse_type) return ((p_analogfunction)(myadmst->_item.p))->_type_isdefault;
  if(myadmst->_pseudo==admse_analogfunction && mypath->_text->_admse==admse_tree) return ((p_analogfunction)(myadmst->_item.p))->_tree_isdefault;
  if(myadmst->_pseudo==admse_analogfunction && mypath->_text->_admse==admse_variable) return ((p_analogfunction)(myadmst->_item.p))->_variable_isdefault;
  if(myadmst->_pseudo==admse_analogfunction && mypath->_text->_admse==admse_attribute) return ((p_analogfunction)(myadmst->_item.p))->_attribute_isdefault;
  if(myadmst->_pseudo==admse_nodealias && mypath->_text->_admse==admse_module) return ((p_nodealias)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_nodealias && mypath->_text->_admse==admse_name) return ((p_nodealias)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_nodealias && mypath->_text->_admse==admse_node) return ((p_nodealias)(myadmst->_item.p))->_node_isdefault;
  if(myadmst->_pseudo==admse_node && mypath->_text->_admse==admse_module) return ((p_node)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_node && mypath->_text->_admse==admse_name) return ((p_node)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_node && mypath->_text->_admse==admse_direction) return ((p_node)(myadmst->_item.p))->_direction_isdefault;
  if(myadmst->_pseudo==admse_node && mypath->_text->_admse==admse_discipline) return ((p_node)(myadmst->_item.p))->_discipline_isdefault;
  if(myadmst->_pseudo==admse_node && mypath->_text->_admse==admse_grounded) return ((p_node)(myadmst->_item.p))->_grounded_isdefault;
  if(myadmst->_pseudo==admse_node && mypath->_text->_admse==admse_location) return ((p_node)(myadmst->_item.p))->_location_isdefault;
  if(myadmst->_pseudo==admse_node && mypath->_text->_admse==admse_attribute) return ((p_node)(myadmst->_item.p))->_attribute_isdefault;
  if(myadmst->_pseudo==admse_branchalias && mypath->_text->_admse==admse_module) return ((p_branchalias)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_branchalias && mypath->_text->_admse==admse_name) return ((p_branchalias)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_branchalias && mypath->_text->_admse==admse_branch) return ((p_branchalias)(myadmst->_item.p))->_branch_isdefault;
  if(myadmst->_pseudo==admse_branch && mypath->_text->_admse==admse_module) return ((p_branch)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_branch && mypath->_text->_admse==admse_pnode) return ((p_branch)(myadmst->_item.p))->_pnode_isdefault;
  if(myadmst->_pseudo==admse_branch && mypath->_text->_admse==admse_nnode) return ((p_branch)(myadmst->_item.p))->_nnode_isdefault;
  if(myadmst->_pseudo==admse_branch && mypath->_text->_admse==admse_discipline) return ((p_branch)(myadmst->_item.p))->_discipline_isdefault;
  if(myadmst->_pseudo==admse_branch && mypath->_text->_admse==admse_grounded) return ((p_branch)(myadmst->_item.p))->_grounded_isdefault;
  if(myadmst->_pseudo==admse_branch && mypath->_text->_admse==admse_attribute) return ((p_branch)(myadmst->_item.p))->_attribute_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_module) return ((p_variableprototype)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_lexval) return ((p_variableprototype)(myadmst->_item.p))->_lexval_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_block) return ((p_variableprototype)(myadmst->_item.p))->_block_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_dependency) return ((p_variableprototype)(myadmst->_item.p))->_dependency_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_static) return ((p_variableprototype)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_dynamic) return ((p_variableprototype)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_sizetype) return ((p_variableprototype)(myadmst->_item.p))->_sizetype_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_parametertype) return ((p_variableprototype)(myadmst->_item.p))->_parametertype_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_type) return ((p_variableprototype)(myadmst->_item.p))->_type_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_maxsize) return ((p_variableprototype)(myadmst->_item.p))->_maxsize_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_minsize) return ((p_variableprototype)(myadmst->_item.p))->_minsize_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_input) return ((p_variableprototype)(myadmst->_item.p))->_input_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_output) return ((p_variableprototype)(myadmst->_item.p))->_output_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_scope) return ((p_variableprototype)(myadmst->_item.p))->_scope_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_default) return ((p_variableprototype)(myadmst->_item.p))->_default_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_derivate) return ((p_variableprototype)(myadmst->_item.p))->_derivate_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_isstate) return ((p_variableprototype)(myadmst->_item.p))->_isstate_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_usedinmodel) return ((p_variableprototype)(myadmst->_item.p))->_usedinmodel_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_usedininstance) return ((p_variableprototype)(myadmst->_item.p))->_usedininstance_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_usedininitial_step) return ((p_variableprototype)(myadmst->_item.p))->_usedininitial_step_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_usedinevaluate) return ((p_variableprototype)(myadmst->_item.p))->_usedinevaluate_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_usedinnoise) return ((p_variableprototype)(myadmst->_item.p))->_usedinnoise_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_usedinfinal) return ((p_variableprototype)(myadmst->_item.p))->_usedinfinal_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_setinmodel) return ((p_variableprototype)(myadmst->_item.p))->_setinmodel_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_setininstance) return ((p_variableprototype)(myadmst->_item.p))->_setininstance_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_setininitial_step) return ((p_variableprototype)(myadmst->_item.p))->_setininitial_step_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_setinevaluate) return ((p_variableprototype)(myadmst->_item.p))->_setinevaluate_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_setinnoise) return ((p_variableprototype)(myadmst->_item.p))->_setinnoise_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_setinfinal) return ((p_variableprototype)(myadmst->_item.p))->_setinfinal_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_setingetprev) return ((p_variableprototype)(myadmst->_item.p))->_setingetprev_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_TemperatureDependent) return ((p_variableprototype)(myadmst->_item.p))->_TemperatureDependent_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_OPdependent) return ((p_variableprototype)(myadmst->_item.p))->_OPdependent_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_insource) return ((p_variableprototype)(myadmst->_item.p))->_insource_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_vcount) return ((p_variableprototype)(myadmst->_item.p))->_vcount_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_vlast) return ((p_variableprototype)(myadmst->_item.p))->_vlast_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_arraydefault) return ((p_variableprototype)(myadmst->_item.p))->_arraydefault_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_attribute) return ((p_variableprototype)(myadmst->_item.p))->_attribute_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_alias) return ((p_variableprototype)(myadmst->_item.p))->_alias_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_range) return ((p_variableprototype)(myadmst->_item.p))->_range_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_probe) return ((p_variableprototype)(myadmst->_item.p))->_probe_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_ddxprobe) return ((p_variableprototype)(myadmst->_item.p))->_ddxprobe_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_variable) return ((p_variableprototype)(myadmst->_item.p))->_variable_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_assignment) return ((p_variableprototype)(myadmst->_item.p))->_assignment_isdefault;
  if(myadmst->_pseudo==admse_variableprototype && mypath->_text->_admse==admse_instance) return ((p_variableprototype)(myadmst->_item.p))->_instance_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_module) return ((p_source)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_branch) return ((p_source)(myadmst->_item.p))->_branch_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_nature) return ((p_source)(myadmst->_item.p))->_nature_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_discipline) return ((p_source)(myadmst->_item.p))->_discipline_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_static) return ((p_source)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_dynamic) return ((p_source)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_whitenoise) return ((p_source)(myadmst->_item.p))->_whitenoise_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_flickernoise) return ((p_source)(myadmst->_item.p))->_flickernoise_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_grounded) return ((p_source)(myadmst->_item.p))->_grounded_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_switch) return ((p_source)(myadmst->_item.p))->_switch_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_type) return ((p_source)(myadmst->_item.p))->_type_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_probe) return ((p_source)(myadmst->_item.p))->_probe_isdefault;
  if(myadmst->_pseudo==admse_source && mypath->_text->_admse==admse_attribute) return ((p_source)(myadmst->_item.p))->_attribute_isdefault;
  if(myadmst->_pseudo==admse_range && mypath->_text->_admse==admse_module) return ((p_range)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_range && mypath->_text->_admse==admse_infexpr) return ((p_range)(myadmst->_item.p))->_infexpr_isdefault;
  if(myadmst->_pseudo==admse_range && mypath->_text->_admse==admse_supexpr) return ((p_range)(myadmst->_item.p))->_supexpr_isdefault;
  if(myadmst->_pseudo==admse_range && mypath->_text->_admse==admse_name) return ((p_range)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_range && mypath->_text->_admse==admse_infboundtype) return ((p_range)(myadmst->_item.p))->_infboundtype_isdefault;
  if(myadmst->_pseudo==admse_range && mypath->_text->_admse==admse_supboundtype) return ((p_range)(myadmst->_item.p))->_supboundtype_isdefault;
  if(myadmst->_pseudo==admse_range && mypath->_text->_admse==admse_type) return ((p_range)(myadmst->_item.p))->_type_isdefault;
  if(myadmst->_pseudo==admse_jacobian && mypath->_text->_admse==admse_module) return ((p_jacobian)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_jacobian && mypath->_text->_admse==admse_row) return ((p_jacobian)(myadmst->_item.p))->_row_isdefault;
  if(myadmst->_pseudo==admse_jacobian && mypath->_text->_admse==admse_column) return ((p_jacobian)(myadmst->_item.p))->_column_isdefault;
  if(myadmst->_pseudo==admse_jacobian && mypath->_text->_admse==admse_diagonal) return ((p_jacobian)(myadmst->_item.p))->_diagonal_isdefault;
  if(myadmst->_pseudo==admse_jacobian && mypath->_text->_admse==admse_static) return ((p_jacobian)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_jacobian && mypath->_text->_admse==admse_dynamic) return ((p_jacobian)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_analog && mypath->_text->_admse==admse_code) return ((p_analog)(myadmst->_item.p))->_code_isdefault;
  if(myadmst->_pseudo==admse_math && mypath->_text->_admse==admse_name) return ((p_math)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_math && mypath->_text->_admse==admse_value) return ((p_math)(myadmst->_item.p))->_value_isdefault;
  if(myadmst->_pseudo==admse_math && mypath->_text->_admse==admse_static) return ((p_math)(myadmst->_item.p))->_static_isdefault;
  if(myadmst->_pseudo==admse_math && mypath->_text->_admse==admse_dynamic) return ((p_math)(myadmst->_item.p))->_dynamic_isdefault;
  if(myadmst->_pseudo==admse_math && mypath->_text->_admse==admse_dependency) return ((p_math)(myadmst->_item.p))->_dependency_isdefault;
  if(myadmst->_pseudo==admse_math && mypath->_text->_admse==admse_attribute) return ((p_math)(myadmst->_item.p))->_attribute_isdefault;
  if(myadmst->_pseudo==admse_string && mypath->_text->_admse==admse_value) return ((p_string)(myadmst->_item.p))->_value_isdefault;
  if(myadmst->_pseudo==admse_subexpression && mypath->_text->_admse==admse_expression) return ((p_subexpression)(myadmst->_item.p))->_expression_isdefault;
  if(myadmst->_pseudo==admse_mapply_unary && mypath->_text->_admse==admse_name) return ((p_mapply_unary)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_mapply_unary && mypath->_text->_admse==admse_arg1) return ((p_mapply_unary)(myadmst->_item.p))->_arg1_isdefault;
  if(myadmst->_pseudo==admse_mapply_binary && mypath->_text->_admse==admse_name) return ((p_mapply_binary)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_mapply_binary && mypath->_text->_admse==admse_arg1) return ((p_mapply_binary)(myadmst->_item.p))->_arg1_isdefault;
  if(myadmst->_pseudo==admse_mapply_binary && mypath->_text->_admse==admse_arg2) return ((p_mapply_binary)(myadmst->_item.p))->_arg2_isdefault;
  if(myadmst->_pseudo==admse_mapply_ternary && mypath->_text->_admse==admse_name) return ((p_mapply_ternary)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_mapply_ternary && mypath->_text->_admse==admse_arg1) return ((p_mapply_ternary)(myadmst->_item.p))->_arg1_isdefault;
  if(myadmst->_pseudo==admse_mapply_ternary && mypath->_text->_admse==admse_arg2) return ((p_mapply_ternary)(myadmst->_item.p))->_arg2_isdefault;
  if(myadmst->_pseudo==admse_mapply_ternary && mypath->_text->_admse==admse_arg3) return ((p_mapply_ternary)(myadmst->_item.p))->_arg3_isdefault;
  if(myadmst->_pseudo==admse_number && mypath->_text->_admse==admse_lexval) return ((p_number)(myadmst->_item.p))->_lexval_isdefault;
  if(myadmst->_pseudo==admse_number && mypath->_text->_admse==admse_scalingunit) return ((p_number)(myadmst->_item.p))->_scalingunit_isdefault;
  if(myadmst->_pseudo==admse_number && mypath->_text->_admse==admse_cast) return ((p_number)(myadmst->_item.p))->_cast_isdefault;
  if(myadmst->_pseudo==admse_function && mypath->_text->_admse==admse_lexval) return ((p_function)(myadmst->_item.p))->_lexval_isdefault;
  if(myadmst->_pseudo==admse_function && mypath->_text->_admse==admse_unique_id) return ((p_function)(myadmst->_item.p))->_unique_id_isdefault;
  if(myadmst->_pseudo==admse_function && mypath->_text->_admse==admse_definition) return ((p_function)(myadmst->_item.p))->_definition_isdefault;
  if(myadmst->_pseudo==admse_function && mypath->_text->_admse==admse_class) return ((p_function)(myadmst->_item.p))->_class_isdefault;
  if(myadmst->_pseudo==admse_function && mypath->_text->_admse==admse_arguments) return ((p_function)(myadmst->_item.p))->_arguments_isdefault;
  if(myadmst->_pseudo==admse_variable && mypath->_text->_admse==admse_prototype) return ((p_variable)(myadmst->_item.p))->_prototype_isdefault;
  if(myadmst->_pseudo==admse_array && mypath->_text->_admse==admse_variable) return ((p_array)(myadmst->_item.p))->_variable_isdefault;
  if(myadmst->_pseudo==admse_array && mypath->_text->_admse==admse_index) return ((p_array)(myadmst->_item.p))->_index_isdefault;
  if(myadmst->_pseudo==admse_probe && mypath->_text->_admse==admse_module) return ((p_probe)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_probe && mypath->_text->_admse==admse_branch) return ((p_probe)(myadmst->_item.p))->_branch_isdefault;
  if(myadmst->_pseudo==admse_probe && mypath->_text->_admse==admse_nature) return ((p_probe)(myadmst->_item.p))->_nature_isdefault;
  if(myadmst->_pseudo==admse_probe && mypath->_text->_admse==admse_seen) return ((p_probe)(myadmst->_item.p))->_seen_isdefault;
  if(myadmst->_pseudo==admse_probe && mypath->_text->_admse==admse_discipline) return ((p_probe)(myadmst->_item.p))->_discipline_isdefault;
  if(myadmst->_pseudo==admse_probe && mypath->_text->_admse==admse_grounded) return ((p_probe)(myadmst->_item.p))->_grounded_isdefault;
  if(myadmst->_pseudo==admse_probe && mypath->_text->_admse==admse_source) return ((p_probe)(myadmst->_item.p))->_source_isdefault;
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_module) return ((p_expression)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_tree) return ((p_expression)(myadmst->_item.p))->_tree_isdefault;
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_hasspecialnumber) return ((p_expression)(myadmst->_item.p))->_hasspecialnumber_isdefault;
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_hasVoltageDependentFunction) return ((p_expression)(myadmst->_item.p))->_hasVoltageDependentFunction_isdefault;
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_infinity) return ((p_expression)(myadmst->_item.p))->_infinity_isdefault;
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_TemperatureDependent) return ((p_expression)(myadmst->_item.p))->_TemperatureDependent_isdefault;
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_value) return ((p_expression)(myadmst->_item.p))->_value_isdefault;
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_function) return ((p_expression)(myadmst->_item.p))->_function_isdefault;
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_probe) return ((p_expression)(myadmst->_item.p))->_probe_isdefault;
  if(myadmst->_pseudo==admse_expression && mypath->_text->_admse==admse_variable) return ((p_expression)(myadmst->_item.p))->_variable_isdefault;
  if(myadmst->_pseudo==admse_instance && mypath->_text->_admse==admse_instantiator) return ((p_instance)(myadmst->_item.p))->_instantiator_isdefault;
  if(myadmst->_pseudo==admse_instance && mypath->_text->_admse==admse_module) return ((p_instance)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_instance && mypath->_text->_admse==admse_name) return ((p_instance)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_instance && mypath->_text->_admse==admse_terminal) return ((p_instance)(myadmst->_item.p))->_terminal_isdefault;
  if(myadmst->_pseudo==admse_instance && mypath->_text->_admse==admse_parameterset) return ((p_instance)(myadmst->_item.p))->_parameterset_isdefault;
  if(myadmst->_pseudo==admse_instanceparameter && mypath->_text->_admse==admse_parameter) return ((p_instanceparameter)(myadmst->_item.p))->_parameter_isdefault;
  if(myadmst->_pseudo==admse_instanceparameter && mypath->_text->_admse==admse_value) return ((p_instanceparameter)(myadmst->_item.p))->_value_isdefault;
  if(myadmst->_pseudo==admse_instancenode && mypath->_text->_admse==admse_nodefrominstantiator) return ((p_instancenode)(myadmst->_item.p))->_nodefrominstantiator_isdefault;
  if(myadmst->_pseudo==admse_instancenode && mypath->_text->_admse==admse_nodefrommodule) return ((p_instancenode)(myadmst->_item.p))->_nodefrommodule_isdefault;
  if(myadmst->_pseudo==admse_nilled && mypath->_text->_admse==admse_module) return ((p_nilled)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_nilled && mypath->_text->_admse==admse_name) return ((p_nilled)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_assignment && mypath->_text->_admse==admse_module) return ((p_assignment)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_assignment && mypath->_text->_admse==admse_lhs) return ((p_assignment)(myadmst->_item.p))->_lhs_isdefault;
  if(myadmst->_pseudo==admse_assignment && mypath->_text->_admse==admse_rhs) return ((p_assignment)(myadmst->_item.p))->_rhs_isdefault;
  if(myadmst->_pseudo==admse_assignment && mypath->_text->_admse==admse_lexval) return ((p_assignment)(myadmst->_item.p))->_lexval_isdefault;
  if(myadmst->_pseudo==admse_assignment && mypath->_text->_admse==admse_name) return ((p_assignment)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_assignment && mypath->_text->_admse==admse_attribute) return ((p_assignment)(myadmst->_item.p))->_attribute_isdefault;
  if(myadmst->_pseudo==admse_contribution && mypath->_text->_admse==admse_module) return ((p_contribution)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_contribution && mypath->_text->_admse==admse_lhs) return ((p_contribution)(myadmst->_item.p))->_lhs_isdefault;
  if(myadmst->_pseudo==admse_contribution && mypath->_text->_admse==admse_rhs) return ((p_contribution)(myadmst->_item.p))->_rhs_isdefault;
  if(myadmst->_pseudo==admse_contribution && mypath->_text->_admse==admse_lexval) return ((p_contribution)(myadmst->_item.p))->_lexval_isdefault;
  if(myadmst->_pseudo==admse_contribution && mypath->_text->_admse==admse_branchalias) return ((p_contribution)(myadmst->_item.p))->_branchalias_isdefault;
  if(myadmst->_pseudo==admse_contribution && mypath->_text->_admse==admse_name) return ((p_contribution)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_contribution && mypath->_text->_admse==admse_whitenoise) return ((p_contribution)(myadmst->_item.p))->_whitenoise_isdefault;
  if(myadmst->_pseudo==admse_contribution && mypath->_text->_admse==admse_flickernoise) return ((p_contribution)(myadmst->_item.p))->_flickernoise_isdefault;
  if(myadmst->_pseudo==admse_contribution && mypath->_text->_admse==admse_attribute) return ((p_contribution)(myadmst->_item.p))->_attribute_isdefault;
  if(myadmst->_pseudo==admse_conditional && mypath->_text->_admse==admse_module) return ((p_conditional)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_conditional && mypath->_text->_admse==admse_if) return ((p_conditional)(myadmst->_item.p))->_if_isdefault;
  if(myadmst->_pseudo==admse_conditional && mypath->_text->_admse==admse_then) return ((p_conditional)(myadmst->_item.p))->_then_isdefault;
  if(myadmst->_pseudo==admse_conditional && mypath->_text->_admse==admse_else) return ((p_conditional)(myadmst->_item.p))->_else_isdefault;
  if(myadmst->_pseudo==admse_conditional && mypath->_text->_admse==admse_name) return ((p_conditional)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_forloop && mypath->_text->_admse==admse_module) return ((p_forloop)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_forloop && mypath->_text->_admse==admse_initial) return ((p_forloop)(myadmst->_item.p))->_initial_isdefault;
  if(myadmst->_pseudo==admse_forloop && mypath->_text->_admse==admse_condition) return ((p_forloop)(myadmst->_item.p))->_condition_isdefault;
  if(myadmst->_pseudo==admse_forloop && mypath->_text->_admse==admse_update) return ((p_forloop)(myadmst->_item.p))->_update_isdefault;
  if(myadmst->_pseudo==admse_forloop && mypath->_text->_admse==admse_forblock) return ((p_forloop)(myadmst->_item.p))->_forblock_isdefault;
  if(myadmst->_pseudo==admse_forloop && mypath->_text->_admse==admse_name) return ((p_forloop)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_whileloop && mypath->_text->_admse==admse_module) return ((p_whileloop)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_whileloop && mypath->_text->_admse==admse_while) return ((p_whileloop)(myadmst->_item.p))->_while_isdefault;
  if(myadmst->_pseudo==admse_whileloop && mypath->_text->_admse==admse_whileblock) return ((p_whileloop)(myadmst->_item.p))->_whileblock_isdefault;
  if(myadmst->_pseudo==admse_whileloop && mypath->_text->_admse==admse_name) return ((p_whileloop)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_case && mypath->_text->_admse==admse_module) return ((p_case)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_case && mypath->_text->_admse==admse_case) return ((p_case)(myadmst->_item.p))->_case_isdefault;
  if(myadmst->_pseudo==admse_case && mypath->_text->_admse==admse_name) return ((p_case)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_case && mypath->_text->_admse==admse_caseitem) return ((p_case)(myadmst->_item.p))->_caseitem_isdefault;
  if(myadmst->_pseudo==admse_caseitem && mypath->_text->_admse==admse_code) return ((p_caseitem)(myadmst->_item.p))->_code_isdefault;
  if(myadmst->_pseudo==admse_caseitem && mypath->_text->_admse==admse_defaultcase) return ((p_caseitem)(myadmst->_item.p))->_defaultcase_isdefault;
  if(myadmst->_pseudo==admse_caseitem && mypath->_text->_admse==admse_condition) return ((p_caseitem)(myadmst->_item.p))->_condition_isdefault;
  if(myadmst->_pseudo==admse_blockvariable && mypath->_text->_admse==admse_block) return ((p_blockvariable)(myadmst->_item.p))->_block_isdefault;
  if(myadmst->_pseudo==admse_blockvariable && mypath->_text->_admse==admse_variable) return ((p_blockvariable)(myadmst->_item.p))->_variable_isdefault;
  if(myadmst->_pseudo==admse_block && mypath->_text->_admse==admse_module) return ((p_block)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_block && mypath->_text->_admse==admse_lexval) return ((p_block)(myadmst->_item.p))->_lexval_isdefault;
  if(myadmst->_pseudo==admse_block && mypath->_text->_admse==admse_block) return ((p_block)(myadmst->_item.p))->_block_isdefault;
  if(myadmst->_pseudo==admse_block && mypath->_text->_admse==admse_item) return ((p_block)(myadmst->_item.p))->_item_isdefault;
  if(myadmst->_pseudo==admse_block && mypath->_text->_admse==admse_attribute) return ((p_block)(myadmst->_item.p))->_attribute_isdefault;
  if(myadmst->_pseudo==admse_block && mypath->_text->_admse==admse_variable) return ((p_block)(myadmst->_item.p))->_variable_isdefault;
  if(myadmst->_pseudo==admse_block && mypath->_text->_admse==admse_probe) return ((p_block)(myadmst->_item.p))->_probe_isdefault;
  if(myadmst->_pseudo==admse_callfunction && mypath->_text->_admse==admse_module) return ((p_callfunction)(myadmst->_item.p))->_module_isdefault;
  if(myadmst->_pseudo==admse_callfunction && mypath->_text->_admse==admse_function) return ((p_callfunction)(myadmst->_item.p))->_function_isdefault;
  if(myadmst->_pseudo==admse_evaluation && mypath->_text->_admse==admse_variable) return ((p_evaluation)(myadmst->_item.p))->_variable_isdefault;
  if(myadmst->_pseudo==admse_attribute && mypath->_text->_admse==admse_name) return ((p_attribute)(myadmst->_item.p))->_name_isdefault;
  if(myadmst->_pseudo==admse_attribute && mypath->_text->_admse==admse_value) return ((p_attribute)(myadmst->_item.p))->_value_isdefault;
  if(myadmst->_pseudo==admse_lexval && mypath->_text->_admse==admse_string) return ((p_lexval)(myadmst->_item.p))->_string_isdefault;
  if(myadmst->_pseudo==admse_lexval && mypath->_text->_admse==admse_f) return ((p_lexval)(myadmst->_item.p))->_f_isdefault;
  if(myadmst->_pseudo==admse_lexval && mypath->_text->_admse==admse_l) return ((p_lexval)(myadmst->_item.p))->_l_isdefault;
  if(myadmst->_pseudo==admse_lexval && mypath->_text->_admse==admse_c) return ((p_lexval)(myadmst->_item.p))->_c_isdefault;
  return 0;
}
static int atomicgroupage (const p_path mypath,p_admst myadmst)
{
  return ((_p_cbcondition)((p_path)mypath->_u->data)->_callback)(((p_path)mypath->_u->data),myadmst);
}
static int unary00 (const p_path mypath,p_admst myadmst)
{
  return !((_p_cbcondition)((p_path)mypath->_u->data)->_callback)(((p_path)mypath->_u->data),myadmst);
}
static int atomictrue (const p_path mypath,p_admst myadmst)
{
  return 1;
}
static int atomicfalse (const p_path mypath,p_admst myadmst)
{
  return 0;
}
static int atomiceq (const p_path mypath,p_admst myadmst)
{
  p_ptraverse p0;
  p_ptraverse p1;
  p_slist myl0;
  p_slist myl1;
  int passed=1;
  p_path root0=(p_path)mypath->_u->data;
  p_path root1=(p_path)mypath->_u->next->data;
  p_slist n000=(p_slist)root0->_bar->data;
  p_slist n01=root0->_bar->next;
  p_slist n001=n000->next;
  p_path l000=(p_path)n000->data;
  p_slist n100=(p_slist)root1->_bar->data;
  p_slist n11=root1->_bar->next;
  p_slist n101=n100->next;
  p_path l100=(p_path)n100->data;
  int isdatatypename0=(l000->_callback==(void*)location03datatypename)&&(n001==NULL)&&(n01==NULL);
  int isquotedstring1=((l100->_callback==(void*)location09)||(l100->_callback==(void*)location09k))&&(n11==NULL)&&(n101==NULL)&&(n11==NULL);
  if(isdatatypename0 && isquotedstring1)
  {
    p_admst myadmst0=aread(myadmst);
    if(myadmst0)
      return (retdatatypename(myadmst0)==l100->_text->_admse);
    else
      return (admse_empty==l100->_text->_admse);
  }
  p0=bar(myadmst,(p_path)mypath->_u->data);
  p1=bar(myadmst,(p_path)mypath->_u->next->data);
  myl0=p0->_admst;
  myl1=p1->_admst;
  if(adms_slist_length(myl0)!=adms_slist_length(myl1))
    passed=0;
  for(;myl0&&passed;myl0=myl0->next,myl1=myl1->next)
  {
    p_admst myadmst0=aread((p_admst)myl0->data);
    p_admst myadmst1=aread((p_admst)myl1->data);
    if(!myadmst0)
      passed=0;
    else
    {
      admse admse0=myadmst0->_pseudo;
      admse admse1=myadmst1->_pseudo;
      if(admse0==admse_empty)
      {}
      else if(admse0==admse_datatypename)
      {
        char* mystring=aprintf(mypath->_transform,myadmst1);
        passed=(myadmst0->_item.i==ns_strtoe(mystring));
        free(mystring);
      }
      else if((admse0==admse_basicinteger)&&(admse1==admse_basicstring))
      {
        char *s=adms_integertostring(myadmst0->_item.i);
        passed=!strcmp(s,myadmst1->_item.s);
        free(s);
      }
      else if((admse0==admse_basicstring)&&(admse1==admse_basicinteger))
      {
        char *s=adms_integertostring(myadmst1->_item.i);
        passed=!strcmp(myadmst0->_item.s,s);
        free(s);
      }
      else if((admse0==admse_basicenumeration)&&(admse1==admse_basicstring))
        passed=!strcmp(ns_etostr(myadmst0->_item.i),myadmst1->_item.s);
      else if((admse0==admse_basicstring)&&(admse1==admse_basicenumeration))
        passed=!strcmp(myadmst0->_item.s,ns_etostr(myadmst1->_item.i));
      else if((admse0==admse_basicenumeration)&&(admse1==admse_basicinteger))
        passed=(myadmst0->_item.i==myadmst1->_item.i);
      else if((admse0==admse_basicinteger)&&(admse1==admse_basicenumeration))
        passed=(myadmst0->_item.i==myadmst1->_item.i);
      else if(admse0!=admse1)
        passed=0;
      else if(admse0==admse_basicenumeration)
        passed=(myadmst0->_item.i==myadmst1->_item.i);
      else if(admse0==admse_basicinteger)
        passed=(myadmst0->_item.i==myadmst1->_item.i);
      else if(admse0==admse_basicreal)
        passed=(myadmst0->_item.r>=myadmst1->_item.r-1.0e-307)&&(myadmst0->_item.r<=myadmst1->_item.r+1.0e-307);
      else if(admse0==admse_basicstring)
        passed=!strcmp(myadmst0->_item.s,myadmst1->_item.s);
      else
        passed=(myadmst0->_item.p==myadmst1->_item.p);
    }
  }
  free_ptraverse(p0);
  free_ptraverse(p1);
  return passed;
}
static int atomicne (const p_path mypath,p_admst myadmst)
{
  return !atomiceq(mypath,myadmst);
}
static int atomiclt (const p_path mypath,p_admst myadmst)
{
  p_ptraverse p0=bar(myadmst,(p_path)mypath->_u->data);
  p_ptraverse p1=bar(myadmst,(p_path)mypath->_u->next->data);
  p_slist myl0=p0->_admst;
  p_slist myl1=p1->_admst;
  int passed=1;
  if(adms_slist_length(myl0)!=adms_slist_length(myl1))
    passed=0;
  else
  {
    for(;myl0&&passed;myl0=myl0->next,myl1=myl1->next)
    {
      p_admst myadmst0=(p_admst)myl0->data;
      p_admst myadmst1=(p_admst)myl1->data;
      admse mytype0=myadmst0->_pseudo;
      admse mytype1=myadmst1->_pseudo;
      if((mytype0==admse_basicinteger)&&(mytype1==admse_basicinteger))
      {
        int myinteger0=myadmst0->_item.i;
        int myinteger1=myadmst1->_item.i;
        passed=(myinteger0<myinteger1);
      }
      else if((mytype0==admse_basicreal)&&(mytype1==admse_basicreal))
      {
        double myreal0=myadmst0->_item.r;
        double myreal1=myadmst1->_item.r;
        passed=(myreal0<myreal1);
      }
      else
      { // Convert the string representation to a number
        double myreal0=strtod(aprintf(mypath->_transform,myadmst0),NULL);
        double myreal1=strtod(aprintf(mypath->_transform,myadmst1),NULL);
        passed=(myreal0<myreal1);
      }
    }
  }
  free_ptraverse(p0);
  free_ptraverse(p1);
  return passed;
}
static int atomicgt (const p_path mypath,p_admst myadmst)
{
  p_ptraverse p0=bar(myadmst,(p_path)mypath->_u->data);
  p_ptraverse p1=bar(myadmst,(p_path)mypath->_u->next->data);
  p_slist myl0=p0->_admst;
  p_slist myl1=p1->_admst;
  int passed=1;
  if(adms_slist_length(myl0)!=adms_slist_length(myl1))
    passed=0;
  else
  {
    for(;myl0&&passed;myl0=myl0->next,myl1=myl1->next)
    {
      p_admst myadmst0=(p_admst)myl0->data;
      p_admst myadmst1=(p_admst)myl1->data;
      admse mytype0=myadmst0->_pseudo;
      admse mytype1=myadmst1->_pseudo;
      if((mytype0==admse_basicinteger)&&(mytype1==admse_basicinteger))
      {
        int myinteger0=myadmst0->_item.i;
        int myinteger1=myadmst1->_item.i;
        passed=(myinteger0>myinteger1);
      }
      else if((mytype0==admse_basicreal)&&(mytype1==admse_basicreal))
      {
        double myreal0=myadmst0->_item.r;
        double myreal1=myadmst1->_item.r;
        passed=(myreal0>myreal1);
      }
      else
      { // Convert the string representation to a number
        double myreal0=strtod(aprintf(mypath->_transform,myadmst0),NULL);
        double myreal1=strtod(aprintf(mypath->_transform,myadmst1),NULL);
        passed=(myreal0>myreal1);
      }
    }
  }
  free_ptraverse(p0);
  free_ptraverse(p1);
  return passed;
}

#if defined(STANDALONE)
#define adms_transform_uid(txt) "unknown"
#endif

static void admstpatherrorimpl (const p_pparse mypparse,char const *s)
{
  adms_message_fatal_continue(("%s - invalid path \"%s\"\n",s,mypparse->_value))
  adms_message_fatal(("see %s\n",adms_transform_uid(mypparse->_transform)))
}


#line 13689 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int admstpathdebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tktk_cr = 258,                 /* tktk_cr  */
    tktk_lf = 259,                 /* tktk_lf  */
    tktk_tab = 260,                /* tktk_tab  */
    tktk_percent = 261,            /* tktk_percent  */
    tktk_percents = 262,           /* tktk_percents  */
    tktk_ticptr = 263,             /* tktk_ticptr  */
    tktk_anytext = 264,            /* tktk_anytext  */
    tktk_goto_atext = 265,         /* tktk_goto_atext  */
    tktk_cquote = 266,             /* tktk_cquote  */
    tktk_openE = 267,              /* tktk_openE  */
    tktk_closeE = 268,             /* tktk_closeE  */
    tktk_dollarvariable = 269,     /* tktk_dollarvariable  */
    tktk_kdollarvariable = 270,    /* tktk_kdollarvariable  */
    tktk_arobavariable = 271,      /* tktk_arobavariable  */
    tktk_karobavariable = 272,     /* tktk_karobavariable  */
    tktk_croixcroixvariable = 273, /* tktk_croixcroixvariable  */
    tktk_croixstar = 274,          /* tktk_croixstar  */
    tktk_kcroixcroixvariable = 275, /* tktk_kcroixcroixvariable  */
    tktk_croixvariable = 276,      /* tktk_croixvariable  */
    tktk_kcroixvariable = 277,     /* tktk_kcroixvariable  */
    tktk_oquote = 278,             /* tktk_oquote  */
    tktk_notequal = 279,           /* tktk_notequal  */
    tktk_gt = 280,                 /* tktk_gt  */
    tktk_lt = 281,                 /* tktk_lt  */
    tktk_star = 282,               /* tktk_star  */
    tktk_incrp = 283,              /* tktk_incrp  */
    tktk_incrm = 284,              /* tktk_incrm  */
    tktk_addp = 285,               /* tktk_addp  */
    tktk_column = 286,             /* tktk_column  */
    tktk_comma = 287,              /* tktk_comma  */
    tktk_bar = 288,                /* tktk_bar  */
    tktk_addm = 289,               /* tktk_addm  */
    tktk_dotdot = 290,             /* tktk_dotdot  */
    tktk_dot = 291,                /* tktk_dot  */
    tktk_slash = 292,              /* tktk_slash  */
    tktk_equal = 293,              /* tktk_equal  */
    tktk_openCond = 294,           /* tktk_openCond  */
    tktk_closeCond = 295,          /* tktk_closeCond  */
    tktk_admst = 296,              /* tktk_admst  */
    tktk_and = 297,                /* tktk_and  */
    tktk_count = 298,              /* tktk_count  */
    tktk_exists = 299,             /* tktk_exists  */
    tktk_false = 300,              /* tktk_false  */
    tktk_id = 301,                 /* tktk_id  */
    tktk_index = 302,              /* tktk_index  */
    tktk_isdefault = 303,          /* tktk_isdefault  */
    tktk_lower_mcase = 304,        /* tktk_lower_mcase  */
    tktk_nilled = 305,             /* tktk_nilled  */
    tktk_not = 306,                /* tktk_not  */
    tktk_or = 307,                 /* tktk_or  */
    tktk_position = 308,           /* tktk_position  */
    tktk_returned = 309,           /* tktk_returned  */
    tktk_reverse = 310,            /* tktk_reverse  */
    tktk_sort = 311,               /* tktk_sort  */
    tktk_text = 312,               /* tktk_text  */
    tktk_true = 313,               /* tktk_true  */
    tktk_uid = 314,                /* tktk_uid  */
    tktk_upper_mcase = 315,        /* tktk_upper_mcase  */
    tktk_ident = 316,              /* tktk_ident  */
    tktk_real = 317,               /* tktk_real  */
    tktk_integer = 318             /* tktk_integer  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define tktk_cr 258
#define tktk_lf 259
#define tktk_tab 260
#define tktk_percent 261
#define tktk_percents 262
#define tktk_ticptr 263
#define tktk_anytext 264
#define tktk_goto_atext 265
#define tktk_cquote 266
#define tktk_openE 267
#define tktk_closeE 268
#define tktk_dollarvariable 269
#define tktk_kdollarvariable 270
#define tktk_arobavariable 271
#define tktk_karobavariable 272
#define tktk_croixcroixvariable 273
#define tktk_croixstar 274
#define tktk_kcroixcroixvariable 275
#define tktk_croixvariable 276
#define tktk_kcroixvariable 277
#define tktk_oquote 278
#define tktk_notequal 279
#define tktk_gt 280
#define tktk_lt 281
#define tktk_star 282
#define tktk_incrp 283
#define tktk_incrm 284
#define tktk_addp 285
#define tktk_column 286
#define tktk_comma 287
#define tktk_bar 288
#define tktk_addm 289
#define tktk_dotdot 290
#define tktk_dot 291
#define tktk_slash 292
#define tktk_equal 293
#define tktk_openCond 294
#define tktk_closeCond 295
#define tktk_admst 296
#define tktk_and 297
#define tktk_count 298
#define tktk_exists 299
#define tktk_false 300
#define tktk_id 301
#define tktk_index 302
#define tktk_isdefault 303
#define tktk_lower_mcase 304
#define tktk_nilled 305
#define tktk_not 306
#define tktk_or 307
#define tktk_position 308
#define tktk_returned 309
#define tktk_reverse 310
#define tktk_sort 311
#define tktk_text 312
#define tktk_true 313
#define tktk_uid 314
#define tktk_upper_mcase 315
#define tktk_ident 316
#define tktk_real 317
#define tktk_integer 318

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13703 "admstpathYacc.y"

p_slist _slist;
p_path _path;
p_text _text;

#line 13871 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE admstpathlval;


int admstpathparse (p_pparse mypparse);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tktk_cr = 3,                    /* tktk_cr  */
  YYSYMBOL_tktk_lf = 4,                    /* tktk_lf  */
  YYSYMBOL_tktk_tab = 5,                   /* tktk_tab  */
  YYSYMBOL_tktk_percent = 6,               /* tktk_percent  */
  YYSYMBOL_tktk_percents = 7,              /* tktk_percents  */
  YYSYMBOL_tktk_ticptr = 8,                /* tktk_ticptr  */
  YYSYMBOL_tktk_anytext = 9,               /* tktk_anytext  */
  YYSYMBOL_tktk_goto_atext = 10,           /* tktk_goto_atext  */
  YYSYMBOL_tktk_cquote = 11,               /* tktk_cquote  */
  YYSYMBOL_tktk_openE = 12,                /* tktk_openE  */
  YYSYMBOL_tktk_closeE = 13,               /* tktk_closeE  */
  YYSYMBOL_tktk_dollarvariable = 14,       /* tktk_dollarvariable  */
  YYSYMBOL_tktk_kdollarvariable = 15,      /* tktk_kdollarvariable  */
  YYSYMBOL_tktk_arobavariable = 16,        /* tktk_arobavariable  */
  YYSYMBOL_tktk_karobavariable = 17,       /* tktk_karobavariable  */
  YYSYMBOL_tktk_croixcroixvariable = 18,   /* tktk_croixcroixvariable  */
  YYSYMBOL_tktk_croixstar = 19,            /* tktk_croixstar  */
  YYSYMBOL_tktk_kcroixcroixvariable = 20,  /* tktk_kcroixcroixvariable  */
  YYSYMBOL_tktk_croixvariable = 21,        /* tktk_croixvariable  */
  YYSYMBOL_tktk_kcroixvariable = 22,       /* tktk_kcroixvariable  */
  YYSYMBOL_tktk_oquote = 23,               /* tktk_oquote  */
  YYSYMBOL_tktk_notequal = 24,             /* tktk_notequal  */
  YYSYMBOL_tktk_gt = 25,                   /* tktk_gt  */
  YYSYMBOL_tktk_lt = 26,                   /* tktk_lt  */
  YYSYMBOL_tktk_star = 27,                 /* tktk_star  */
  YYSYMBOL_tktk_incrp = 28,                /* tktk_incrp  */
  YYSYMBOL_tktk_incrm = 29,                /* tktk_incrm  */
  YYSYMBOL_tktk_addp = 30,                 /* tktk_addp  */
  YYSYMBOL_tktk_column = 31,               /* tktk_column  */
  YYSYMBOL_tktk_comma = 32,                /* tktk_comma  */
  YYSYMBOL_tktk_bar = 33,                  /* tktk_bar  */
  YYSYMBOL_tktk_addm = 34,                 /* tktk_addm  */
  YYSYMBOL_tktk_dotdot = 35,               /* tktk_dotdot  */
  YYSYMBOL_tktk_dot = 36,                  /* tktk_dot  */
  YYSYMBOL_tktk_slash = 37,                /* tktk_slash  */
  YYSYMBOL_tktk_equal = 38,                /* tktk_equal  */
  YYSYMBOL_tktk_openCond = 39,             /* tktk_openCond  */
  YYSYMBOL_tktk_closeCond = 40,            /* tktk_closeCond  */
  YYSYMBOL_tktk_admst = 41,                /* tktk_admst  */
  YYSYMBOL_tktk_and = 42,                  /* tktk_and  */
  YYSYMBOL_tktk_count = 43,                /* tktk_count  */
  YYSYMBOL_tktk_exists = 44,               /* tktk_exists  */
  YYSYMBOL_tktk_false = 45,                /* tktk_false  */
  YYSYMBOL_tktk_id = 46,                   /* tktk_id  */
  YYSYMBOL_tktk_index = 47,                /* tktk_index  */
  YYSYMBOL_tktk_isdefault = 48,            /* tktk_isdefault  */
  YYSYMBOL_tktk_lower_mcase = 49,          /* tktk_lower_mcase  */
  YYSYMBOL_tktk_nilled = 50,               /* tktk_nilled  */
  YYSYMBOL_tktk_not = 51,                  /* tktk_not  */
  YYSYMBOL_tktk_or = 52,                   /* tktk_or  */
  YYSYMBOL_tktk_position = 53,             /* tktk_position  */
  YYSYMBOL_tktk_returned = 54,             /* tktk_returned  */
  YYSYMBOL_tktk_reverse = 55,              /* tktk_reverse  */
  YYSYMBOL_tktk_sort = 56,                 /* tktk_sort  */
  YYSYMBOL_tktk_text = 57,                 /* tktk_text  */
  YYSYMBOL_tktk_true = 58,                 /* tktk_true  */
  YYSYMBOL_tktk_uid = 59,                  /* tktk_uid  */
  YYSYMBOL_tktk_upper_mcase = 60,          /* tktk_upper_mcase  */
  YYSYMBOL_tktk_ident = 61,                /* tktk_ident  */
  YYSYMBOL_tktk_real = 62,                 /* tktk_real  */
  YYSYMBOL_tktk_integer = 63,              /* tktk_integer  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_root = 65,                      /* root  */
  YYSYMBOL_pathroot_l = 66,                /* pathroot_l  */
  YYSYMBOL_pathroot = 67,                  /* pathroot  */
  YYSYMBOL_pathbar = 68,                   /* pathbar  */
  YYSYMBOL_pathadd = 69,                   /* pathadd  */
  YYSYMBOL_pathmult = 70,                  /* pathmult  */
  YYSYMBOL_pathunary = 71,                 /* pathunary  */
  YYSYMBOL_pathincr = 72,                  /* pathincr  */
  YYSYMBOL_pathsep0 = 73,                  /* pathsep0  */
  YYSYMBOL_pathsep = 74,                   /* pathsep  */
  YYSYMBOL_locationcondition = 75,         /* locationcondition  */
  YYSYMBOL_identifier = 76,                /* identifier  */
  YYSYMBOL_location = 77,                  /* location  */
  YYSYMBOL_quotedstring = 78,              /* quotedstring  */
  YYSYMBOL_atext = 79,                     /* atext  */
  YYSYMBOL_atextitem = 80,                 /* atextitem  */
  YYSYMBOL_condition = 81,                 /* condition  */
  YYSYMBOL_expression = 82,                /* expression  */
  YYSYMBOL_binaryor = 83,                  /* binaryor  */
  YYSYMBOL_binaryand = 84,                 /* binaryand  */
  YYSYMBOL_unary = 85,                     /* unary  */
  YYSYMBOL_atomic = 86                     /* atomic  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  95
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   493

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0, 13710, 13710, 13713, 13721, 13725, 13731, 13741, 13746, 13753,
   13757, 13767, 13779, 13783, 13793, 13805, 13809, 13818, 13829, 13833,
   13844, 13857, 13862, 13867, 13876, 13887, 13892, 13899, 13904, 13911,
   13915, 13923, 13929, 13935, 13941, 13947, 13953, 13967, 13973, 13979,
   13985, 13991, 13997, 14005, 14013, 14021, 14029, 14044, 14051, 14058,
   14065, 14072, 14079, 14086, 14093, 14100, 14106, 14114, 14121, 14128,
   14134, 14140, 14152, 14165, 14173, 14178, 14185, 14189, 14193, 14197,
   14201, 14206, 14211, 14217, 14223, 14229, 14233, 14242, 14246, 14256,
   14260, 14270, 14274, 14283, 14290, 14298, 14306, 14314, 14322, 14329,
   14336, 14342, 14348
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tktk_cr", "tktk_lf",
  "tktk_tab", "tktk_percent", "tktk_percents", "tktk_ticptr",
  "tktk_anytext", "tktk_goto_atext", "tktk_cquote", "tktk_openE",
  "tktk_closeE", "tktk_dollarvariable", "tktk_kdollarvariable",
  "tktk_arobavariable", "tktk_karobavariable", "tktk_croixcroixvariable",
  "tktk_croixstar", "tktk_kcroixcroixvariable", "tktk_croixvariable",
  "tktk_kcroixvariable", "tktk_oquote", "tktk_notequal", "tktk_gt",
  "tktk_lt", "tktk_star", "tktk_incrp", "tktk_incrm", "tktk_addp",
  "tktk_column", "tktk_comma", "tktk_bar", "tktk_addm", "tktk_dotdot",
  "tktk_dot", "tktk_slash", "tktk_equal", "tktk_openCond",
  "tktk_closeCond", "tktk_admst", "tktk_and", "tktk_count", "tktk_exists",
  "tktk_false", "tktk_id", "tktk_index", "tktk_isdefault",
  "tktk_lower_mcase", "tktk_nilled", "tktk_not", "tktk_or",
  "tktk_position", "tktk_returned", "tktk_reverse", "tktk_sort",
  "tktk_text", "tktk_true", "tktk_uid", "tktk_upper_mcase", "tktk_ident",
  "tktk_real", "tktk_integer", "$accept", "root", "pathroot_l", "pathroot",
  "pathbar", "pathadd", "pathmult", "pathunary", "pathincr", "pathsep0",
  "pathsep", "locationcondition", "identifier", "location", "quotedstring",
  "atext", "atextitem", "condition", "expression", "binaryor", "binaryand",
  "unary", "atomic", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-103)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      20,  -103,   478,   240,   478,  -103,   478,  -103,   478,  -103,
    -103,   478,  -103,   103,   296,   296,  -103,  -103,   352,   128,
      -3,     5,     8,    13,    15,    17,    19,    21,    33,    37,
      50,    66,    77,  -103,  -103,    92,    63,  -103,    69,   -23,
     -15,  -103,  -103,    23,    67,  -103,    91,    72,  -103,  -103,
    -103,  -103,  -103,   240,  -103,  -103,   478,  -103,   478,  -103,
     102,   413,   426,   439,   452,  -103,   375,  -103,  -103,    79,
     128,   108,   109,   111,   112,   184,   113,    22,    90,    80,
      89,  -103,  -103,    97,   240,   240,   240,   240,    98,   114,
     240,   240,   114,   240,   240,  -103,   240,   240,   240,   240,
     240,   240,  -103,  -103,   352,   240,  -103,   122,   465,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,   352,    75,    -8,   240,
     125,    78,   240,    22,  -103,   139,   240,   240,   240,   240,
    -103,   128,   128,   140,   141,   142,   124,   144,   146,   147,
     148,   153,   155,   167,   180,  -103,   -23,   -15,   -15,  -103,
    -103,  -103,   181,  -103,  -103,  -103,   182,  -103,   195,   196,
    -103,  -103,  -103,  -103,  -103,    89,  -103,  -103,  -103,  -103,
     240,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,   197,  -103
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    61,     0,     0,     0,    38,     0,    39,     0,    60,
      41,     0,    40,     0,     0,     0,    33,    32,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    35,    34,     0,     2,     4,     6,     7,
       9,    12,    15,    18,    21,    25,     0,    29,    46,    28,
      66,    67,    68,     0,    70,    69,     0,    72,     3,    64,
       0,     0,     0,     0,     0,    63,     0,    16,    17,    23,
       0,     0,     0,     0,     0,     0,     0,    76,     0,    75,
      77,    79,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,    19,    20,    22,     0,    27,     0,     0,    65,
      30,    42,    43,    45,    44,    62,    24,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     8,    10,    11,    13,
      14,    26,     0,    73,    71,    83,     0,    92,     0,     0,
      91,    85,    87,    86,    84,    78,    80,    55,    54,    49,
       0,    53,    59,    58,    51,    50,    57,    48,    52,    47,
      89,    90,    88,     0,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,  -103,     0,  -103,    44,   -34,   -29,    83,  -103,
     179,  -102,  -103,  -103,   -88,     2,   -40,   164,  -103,   143,
      81,    84,   149
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    35,    36,   123,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    58,    59,    49,    78,    79,
      80,    81,    82
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,   139,   151,    60,   142,   155,    61,    98,    62,    83,
      63,    99,   100,    64,   151,    66,   101,    84,   109,    77,
      85,   109,   109,   109,   109,    86,   109,    87,     1,    88,
       2,    89,     3,    90,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,   131,    91,   126,   127,   128,    92,
      14,   102,   103,   107,    15,    16,    17,    18,   108,    19,
     129,    20,    93,    21,   147,   148,    22,    23,   109,    24,
     117,   149,   150,    25,    26,    27,    28,    29,    94,    30,
      31,    32,    33,    34,   134,   135,   136,   137,   110,   -31,
     140,   141,    95,   143,   144,    96,   145,    67,    68,   126,
     127,   128,    97,   105,   104,   152,    50,    51,    52,    53,
      54,    19,    55,   129,    65,   110,   116,    56,    57,   156,
     119,   120,   159,   121,   122,   125,   161,   162,   163,   164,
     130,   132,   131,   133,   138,   153,     1,    13,   157,   158,
      70,   146,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,   160,   167,   168,   169,   170,   171,    14,   172,
     173,   174,    15,    16,    17,    18,   175,    19,   176,    20,
     183,    21,    71,    72,    22,    23,    73,    24,    74,    75,
     177,    25,    26,    27,    28,    29,    76,    30,    31,    32,
      33,    34,     1,   178,   179,   180,    70,    69,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,   181,   182,
     184,   106,   165,   118,    14,     0,   166,     0,    15,    16,
      17,    18,     0,    19,   124,    20,     0,    21,    71,    72,
      22,    23,    73,    24,    74,     0,     0,    25,    26,    27,
      28,    29,    76,    30,    31,    32,    33,    34,     1,     0,
       0,     0,     3,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,    15,    16,    17,    18,     0,    19,
       0,    20,     0,    21,     0,     0,    22,    23,     0,    24,
       0,     0,     0,    25,    26,    27,    28,    29,     0,    30,
      31,    32,    33,    34,     1,     0,     0,     0,     3,     0,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    17,    18,     0,    19,     0,    20,     0,    21,
       0,     0,    22,    23,     0,    24,     0,     0,     0,    25,
      26,    27,    28,    29,     0,    30,    31,    32,    33,    34,
       1,     0,     0,     0,     3,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,    50,    51,
      52,    53,    54,     0,    55,     0,   115,    16,    17,    56,
      57,    19,     0,    20,     0,    21,     0,     0,    22,    23,
       0,    24,     0,     0,     0,    25,    26,    27,    28,    29,
       0,    30,    31,    32,    33,    34,    50,    51,    52,    53,
      54,     0,    55,     0,     0,     0,   111,    56,    57,    50,
      51,    52,    53,    54,     0,    55,     0,     0,     0,   112,
      56,    57,    50,    51,    52,    53,    54,     0,    55,     0,
       0,     0,   113,    56,    57,    50,    51,    52,    53,    54,
       0,    55,     0,     0,     0,   114,    56,    57,    50,    51,
      52,    53,    54,     0,    55,     0,     0,     0,   154,    56,
      57,    50,    51,    52,    53,    54,     0,    55,     0,     0,
       0,     0,    56,    57
};

static const yytype_int16 yycheck[] =
{
       0,    89,   104,     3,    92,    13,     4,    30,     6,    12,
       8,    34,    27,    11,   116,    13,    31,    12,    58,    19,
      12,    61,    62,    63,    64,    12,    66,    12,     8,    12,
      10,    12,    12,    12,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    52,    12,    24,    25,    26,    12,
      30,    28,    29,    53,    34,    35,    36,    37,    56,    39,
      38,    41,    12,    43,    98,    99,    46,    47,   108,    49,
      70,   100,   101,    53,    54,    55,    56,    57,    12,    59,
      60,    61,    62,    63,    84,    85,    86,    87,    13,    12,
      90,    91,     0,    93,    94,    32,    96,    14,    15,    24,
      25,    26,    33,    12,    37,   105,     3,     4,     5,     6,
       7,    39,     9,    38,    11,    13,    37,    14,    15,   119,
      12,    12,   122,    12,    12,    12,   126,   127,   128,   129,
      40,    42,    52,    36,    36,    13,     8,    23,    13,    61,
      12,    97,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    13,    13,    13,    13,    32,    13,    30,    13,
      13,    13,    34,    35,    36,    37,    13,    39,    13,    41,
     170,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      13,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     8,    13,    13,    13,    12,    18,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    13,    13,
      13,    47,   131,    70,    30,    -1,   132,    -1,    34,    35,
      36,    37,    -1,    39,    75,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     8,    -1,
      -1,    -1,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    36,    37,    -1,    39,
      -1,    41,    -1,    43,    -1,    -1,    46,    47,    -1,    49,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    59,
      60,    61,    62,    63,     8,    -1,    -1,    -1,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    -1,    39,    -1,    41,    -1,    43,
      -1,    -1,    46,    47,    -1,    49,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    59,    60,    61,    62,    63,
       8,    -1,    -1,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    -1,    11,    35,    36,    14,
      15,    39,    -1,    41,    -1,    43,    -1,    -1,    46,    47,
      -1,    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    63,     3,     4,     5,     6,
       7,    -1,     9,    -1,    -1,    -1,    13,    14,    15,     3,
       4,     5,     6,     7,    -1,     9,    -1,    -1,    -1,    13,
      14,    15,     3,     4,     5,     6,     7,    -1,     9,    -1,
      -1,    -1,    13,    14,    15,     3,     4,     5,     6,     7,
      -1,     9,    -1,    -1,    -1,    13,    14,    15,     3,     4,
       5,     6,     7,    -1,     9,    -1,    -1,    -1,    13,    14,
      15,     3,     4,     5,     6,     7,    -1,     9,    -1,    -1,
      -1,    -1,    14,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,    10,    12,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    30,    34,    35,    36,    37,    39,
      41,    43,    46,    47,    49,    53,    54,    55,    56,    57,
      59,    60,    61,    62,    63,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    81,
       3,     4,     5,     6,     7,     9,    14,    15,    79,    80,
      67,    79,    79,    79,    79,    11,    79,    72,    72,    74,
      12,    44,    45,    48,    50,    51,    58,    67,    82,    83,
      84,    85,    86,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,     0,    32,    33,    30,    34,
      27,    31,    28,    29,    37,    12,    81,    67,    79,    80,
      13,    13,    13,    13,    13,    11,    37,    67,    83,    12,
      12,    12,    12,    67,    86,    12,    24,    25,    26,    38,
      40,    52,    42,    36,    67,    67,    67,    67,    36,    78,
      67,    67,    78,    67,    67,    67,    69,    70,    70,    71,
      71,    75,    67,    13,    13,    13,    67,    13,    61,    67,
      13,    67,    67,    67,    67,    84,    85,    13,    13,    13,
      32,    13,    13,    13,    13,    13,    13,    13,    13,    13,
      13,    13,    13,    67,    13
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    67,    68,    68,    69,
      69,    69,    70,    70,    70,    71,    71,    71,    72,    72,
      72,    73,    73,    73,    73,    74,    74,    75,    75,    75,
      75,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     1,     1,     3,     1,
       3,     3,     1,     3,     3,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     3,     1,     3,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     4,
       1,     1,     3,     2,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     3,     3,     1,     1,     1,     3,     1,
       3,     1,     2,     3,     3,     3,     3,     3,     4,     4,
       4,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (mypparse, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, mypparse); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, p_pparse mypparse)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (mypparse);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, p_pparse mypparse)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, mypparse);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, p_pparse mypparse)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], mypparse);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, mypparse); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, p_pparse mypparse)
{
  YY_USE (yyvaluep);
  YY_USE (mypparse);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (p_pparse mypparse)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (mypparse);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* root: pathroot_l  */
#line 13711 "admstpathYacc.y"
 {/*0*/
 }
#line 15132 "y.tab.c"
    break;

  case 3: /* root: tktk_goto_atext atext  */
#line 13714 "admstpathYacc.y"
 {/*1*/
   p_text mytext=adms_text_new(((p_pparse)mypparse)->_transform,"");
   mytext->_token=adms_slist_reverse((yyvsp[0]._slist));
   ((p_pparse)mypparse)->_text=mytext;
 }
#line 15142 "y.tab.c"
    break;

  case 4: /* pathroot_l: pathroot  */
#line 13722 "admstpathYacc.y"
 {/*0*/
   ((p_pparse)mypparse)->_path=(yyvsp[0]._path);
 }
#line 15150 "y.tab.c"
    break;

  case 5: /* pathroot_l: pathroot_l tktk_comma pathroot  */
#line 13726 "admstpathYacc.y"
 {/*1*/
   ((p_pparse)mypparse)->_path=(yyvsp[0]._path);
 }
#line 15158 "y.tab.c"
    break;

  case 6: /* pathroot: pathbar  */
#line 13732 "admstpathYacc.y"
 {/*0*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   adms_slist_inreverse(&(yyvsp[0]._slist));
   (yyval._path)->_bar=(yyvsp[0]._slist);
   (yyval._path)->_callback=NULL;
   (yyval._path)->_callbackname="path";
 }
#line 15170 "y.tab.c"
    break;

  case 7: /* pathbar: pathadd  */
#line 13742 "admstpathYacc.y"
 {/*0*/
   (yyval._slist)=NULL;
   adms_slist_push(&(yyval._slist),(p_adms)(yyvsp[0]._slist));
 }
#line 15179 "y.tab.c"
    break;

  case 8: /* pathbar: pathbar tktk_bar pathadd  */
#line 13747 "admstpathYacc.y"
 {/*1*/
   (yyval._slist)=(yyvsp[-2]._slist);
   adms_slist_push(&(yyval._slist),(p_adms)(yyvsp[0]._slist));
 }
#line 15188 "y.tab.c"
    break;

  case 9: /* pathadd: pathmult  */
#line 13754 "admstpathYacc.y"
 {/*0*/
   (yyval._slist)=(yyvsp[0]._slist);
 }
#line 15196 "y.tab.c"
    break;

  case 10: /* pathadd: pathadd tktk_addp pathmult  */
#line 13758 "admstpathYacc.y"
 {/*1*/
   p_path addp=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   addp->_callback=(void*)addptraverse;
   addp->_callbackname="addptraverse";
   adms_slist_push(&addp->_arg,(p_adms)(yyvsp[0]._slist));
   adms_slist_push(&addp->_arg,(p_adms)(yyvsp[-2]._slist));
   (yyval._slist)=NULL;
   adms_slist_push(&(yyval._slist),(p_adms)addp);
 }
#line 15210 "y.tab.c"
    break;

  case 11: /* pathadd: pathadd tktk_addm pathmult  */
#line 13768 "admstpathYacc.y"
 {/*2*/
   p_path addm=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   addm->_callback=(void*)addmtraverse;
   addm->_callbackname="addmtraverse";
   adms_slist_push(&addm->_arg,(p_adms)(yyvsp[0]._slist));
   adms_slist_push(&addm->_arg,(p_adms)(yyvsp[-2]._slist));
   (yyval._slist)=NULL;
   adms_slist_push(&(yyval._slist),(p_adms)addm);
 }
#line 15224 "y.tab.c"
    break;

  case 12: /* pathmult: pathunary  */
#line 13780 "admstpathYacc.y"
 {/*0*/
   (yyval._slist)=(yyvsp[0]._slist);
 }
#line 15232 "y.tab.c"
    break;

  case 13: /* pathmult: pathmult tktk_star pathunary  */
#line 13784 "admstpathYacc.y"
 {/*1*/
   p_path multp=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   multp->_callback=(void*)multtimetraverse;
   multp->_callbackname="multtimetraverse";
   adms_slist_push(&multp->_arg,(p_adms)(yyvsp[0]._slist));
   adms_slist_push(&multp->_arg,(p_adms)(yyvsp[-2]._slist));
   (yyval._slist)=NULL;
   adms_slist_push(&(yyval._slist),(p_adms)multp);
 }
#line 15246 "y.tab.c"
    break;

  case 14: /* pathmult: pathmult tktk_column pathunary  */
#line 13794 "admstpathYacc.y"
 {/*2*/
   p_path multm=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   multm->_callback=(void*)multdivtraverse;
   multm->_callbackname="multdivtraverse";
   adms_slist_push(&multm->_arg,(p_adms)(yyvsp[0]._slist));
   adms_slist_push(&multm->_arg,(p_adms)(yyvsp[-2]._slist));
   (yyval._slist)=NULL;
   adms_slist_push(&(yyval._slist),(p_adms)multm);
 }
#line 15260 "y.tab.c"
    break;

  case 15: /* pathunary: pathincr  */
#line 13806 "admstpathYacc.y"
 {/*0*/
   (yyval._slist)=(yyvsp[0]._slist);
 }
#line 15268 "y.tab.c"
    break;

  case 16: /* pathunary: tktk_addp pathincr  */
#line 13810 "admstpathYacc.y"
 {/*1*/
   p_path unaryp=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   unaryp->_callback=(void*)unaryptraverse;
   unaryp->_callbackname="unaryptraverse";
   adms_slist_push(&unaryp->_arg,(p_adms)(yyvsp[0]._slist));
   (yyval._slist)=NULL;
   adms_slist_push(&(yyval._slist),(p_adms)unaryp);
 }
#line 15281 "y.tab.c"
    break;

  case 17: /* pathunary: tktk_addm pathincr  */
#line 13819 "admstpathYacc.y"
 {/*2*/
   p_path unarym=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   unarym->_callback=(void*)unarymtraverse;
   unarym->_callbackname="unarymtraverse";
   adms_slist_push(&unarym->_arg,(p_adms)(yyvsp[0]._slist));
   (yyval._slist)=NULL;
   adms_slist_push(&(yyval._slist),(p_adms)unarym);
 }
#line 15294 "y.tab.c"
    break;

  case 18: /* pathincr: pathsep0  */
#line 13830 "admstpathYacc.y"
 {/*0*/
   (yyval._slist)=(yyvsp[0]._slist);
 }
#line 15302 "y.tab.c"
    break;

  case 19: /* pathincr: pathsep0 tktk_incrp  */
#line 13834 "admstpathYacc.y"
 {/*1*/
   p_path incrp=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   p_path path0=(p_path)adms_slist_last((yyvsp[-1]._slist))->data;
   path0->_keeplist=1;
   incrp->_callback=(void*)incrptraverse;
   incrp->_callbackname="incrptraverse";
   adms_slist_push(&incrp->_arg,(p_adms)(yyvsp[-1]._slist));
   (yyval._slist)=NULL;
   adms_slist_push(&(yyval._slist),(p_adms)incrp);
 }
#line 15317 "y.tab.c"
    break;

  case 20: /* pathincr: pathsep0 tktk_incrm  */
#line 13845 "admstpathYacc.y"
 {/*2*/
   p_path incrm=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   p_path path0=(p_path)adms_slist_last((yyvsp[-1]._slist))->data;
   path0->_keeplist=1;
   incrm->_callback=(void*)incrmtraverse;
   incrm->_callbackname="incrmtraverse";
   adms_slist_push(&incrm->_arg,(p_adms)(yyvsp[-1]._slist));
   (yyval._slist)=NULL;
   adms_slist_push(&(yyval._slist),(p_adms)incrm);
 }
#line 15332 "y.tab.c"
    break;

  case 21: /* pathsep0: pathsep  */
#line 13858 "admstpathYacc.y"
 {/*0*/
   (yyval._slist)=(yyvsp[0]._slist);
   adms_slist_inreverse(&(yyval._slist));
 }
#line 15341 "y.tab.c"
    break;

  case 22: /* pathsep0: pathsep tktk_slash  */
#line 13863 "admstpathYacc.y"
 {/*1*/
   (yyval._slist)=(yyvsp[-1]._slist);
   adms_slist_inreverse(&(yyval._slist));
 }
#line 15350 "y.tab.c"
    break;

  case 23: /* pathsep0: tktk_slash pathsep  */
#line 13868 "admstpathYacc.y"
 {/*2*/
   p_path pathroot=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   pathroot->_callback=(void*)root00;
   pathroot->_callbackname="root00";
   (yyval._slist)=(yyvsp[0]._slist);
   adms_slist_inreverse(&(yyval._slist));
   adms_slist_push(&(yyval._slist),(p_adms)pathroot);
 }
#line 15363 "y.tab.c"
    break;

  case 24: /* pathsep0: tktk_slash pathsep tktk_slash  */
#line 13877 "admstpathYacc.y"
 {/*3*/
   p_path pathroot=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   pathroot->_callback=(void*)root00;
   pathroot->_callbackname="root00";
   (yyval._slist)=(yyvsp[-1]._slist);
   adms_slist_inreverse(&(yyval._slist));
   adms_slist_push(&(yyval._slist),(p_adms)pathroot);
 }
#line 15376 "y.tab.c"
    break;

  case 25: /* pathsep: locationcondition  */
#line 13888 "admstpathYacc.y"
 {/*0*/
   (yyval._slist)=NULL;
   adms_slist_push(&(yyval._slist),(p_adms)(yyvsp[0]._path));
 }
#line 15385 "y.tab.c"
    break;

  case 26: /* pathsep: pathsep tktk_slash locationcondition  */
#line 13893 "admstpathYacc.y"
 {/*1*/
   (yyval._slist)=(yyvsp[-2]._slist);
   adms_slist_push(&(yyval._slist),(p_adms)(yyvsp[0]._path));
 }
#line 15394 "y.tab.c"
    break;

  case 27: /* locationcondition: location condition  */
#line 13900 "admstpathYacc.y"
 {/*0*/
   (yyval._path)=(yyvsp[-1]._path);
   if((yyvsp[0]._path)) adms_slist_push(&(yyval._path)->_c,(p_adms)(yyvsp[0]._path));
 }
#line 15403 "y.tab.c"
    break;

  case 28: /* locationcondition: condition  */
#line 13905 "admstpathYacc.y"
 {/*1*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)location00;
   (yyval._path)->_callbackname="location00";
   if((yyvsp[0]._path)) adms_slist_push(&(yyval._path)->_c,(p_adms)(yyvsp[0]._path));
 }
#line 15414 "y.tab.c"
    break;

  case 29: /* locationcondition: location  */
#line 13912 "admstpathYacc.y"
 {/*2*/
   (yyval._path)=(yyvsp[0]._path);
 }
#line 15422 "y.tab.c"
    break;

  case 30: /* locationcondition: tktk_openE pathroot tktk_closeE  */
#line 13916 "admstpathYacc.y"
 {/*3*/
   (yyval._path)=(yyvsp[-1]._path);
   (yyval._path)->_callbackname="groupage";
   (yyval._path)->_callback=(void*)groupage;
 }
#line 15432 "y.tab.c"
    break;

  case 31: /* identifier: tktk_ident  */
#line 13924 "admstpathYacc.y"
 {/*0*/
   (yyval._path)=BASICSTRING((p_pparse)mypparse,adms_knclone(((p_pparse)mypparse)->_tkstart,((p_pparse)mypparse)->_tklen));
 }
#line 15440 "y.tab.c"
    break;

  case 32: /* location: tktk_dot  */
#line 13930 "admstpathYacc.y"
 {/*0 dot*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)location00;
   (yyval._path)->_callbackname="location00.dot";
 }
#line 15450 "y.tab.c"
    break;

  case 33: /* location: tktk_dotdot  */
#line 13936 "admstpathYacc.y"
 {/*1 dotdot*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)location01;
   (yyval._path)->_callbackname="location01.dotdot";
 }
#line 15460 "y.tab.c"
    break;

  case 34: /* location: tktk_integer  */
#line 13942 "admstpathYacc.y"
 {/*10 intp*/
   (yyval._path)=BASICINTEGER((p_pparse)mypparse,adms_knclone(((p_pparse)mypparse)->_tkstart,((p_pparse)mypparse)->_tklen));
   (yyval._path)->_callback=(void*)location10;
   (yyval._path)->_callbackname="location10.intp";
 }
#line 15470 "y.tab.c"
    break;

  case 35: /* location: tktk_real  */
#line 13948 "admstpathYacc.y"
 {/*7 realp*/
   (yyval._path)=BASICSTRING((p_pparse)mypparse,adms_knclone(((p_pparse)mypparse)->_tkstart,((p_pparse)mypparse)->_tklen));
   (yyval._path)->_callback=(void*)location07;
   (yyval._path)->_callbackname="location07.realp";
 }
#line 15480 "y.tab.c"
    break;

  case 36: /* location: tktk_ident  */
#line 13954 "admstpathYacc.y"
 {/*3 ident*/
   (yyval._path)=BASICSTRING((p_pparse)mypparse,adms_knclone(((p_pparse)mypparse)->_tkstart,((p_pparse)mypparse)->_tklen));
   if(((yyval._path)->_text->_admse==admse_past_name)||((yyval._path)->_text->_admse==admse_datatypefamily))
   {
     (yyval._path)->_callback=(void*)location03dummy;
     (yyval._path)->_callbackname="location03dummy";
   }
   else
   {
     (yyval._path)->_callback=(void*)location03;
     (yyval._path)->_callbackname="location03";
   }
 }
#line 15498 "y.tab.c"
    break;

  case 37: /* location: tktk_index  */
#line 13968 "admstpathYacc.y"
 {/*3 ident.index*/
   (yyval._path)=BASICSTRING((p_pparse)mypparse,"index");
   (yyval._path)->_callback=(void*)location03;
   (yyval._path)->_callbackname="location03.ident.index";
 }
#line 15508 "y.tab.c"
    break;

  case 38: /* location: tktk_kdollarvariable  */
#line 13974 "admstpathYacc.y"
 {/*4 kdollar*/
   (yyval._path)=BASICSTRING((p_pparse)mypparse,adms_knclone(((p_pparse)mypparse)->_tkstart,((p_pparse)mypparse)->_tklen));
   (yyval._path)->_callback=(void*)location04;
   (yyval._path)->_callbackname="location04.kdollar";
 }
#line 15518 "y.tab.c"
    break;

  case 39: /* location: tktk_karobavariable  */
#line 13980 "admstpathYacc.y"
 {/*5 karoba*/
   (yyval._path)=BASICSTRING((p_pparse)mypparse,adms_knclone(((p_pparse)mypparse)->_tkstart,((p_pparse)mypparse)->_tklen));
   (yyval._path)->_callback=(void*)location05;
   (yyval._path)->_callbackname="location05.karoba";
 }
#line 15528 "y.tab.c"
    break;

  case 40: /* location: tktk_kcroixvariable  */
#line 13986 "admstpathYacc.y"
 {/*13 kcroix*/
   (yyval._path)=BASICSTRING((p_pparse)mypparse,adms_knclone(((p_pparse)mypparse)->_tkstart,((p_pparse)mypparse)->_tklen));
   (yyval._path)->_callback=(void*)location13;
   (yyval._path)->_callbackname="location13.kcroix";
 }
#line 15538 "y.tab.c"
    break;

  case 41: /* location: tktk_kcroixcroixvariable  */
#line 13992 "admstpathYacc.y"
 {/*12 kcroixcroix*/
   (yyval._path)=BASICSTRING((p_pparse)mypparse,adms_knclone(((p_pparse)mypparse)->_tkstart,((p_pparse)mypparse)->_tklen));
   (yyval._path)->_callback=(void*)location12;
   (yyval._path)->_callbackname="location12.kcroixcroix";
 }
#line 15548 "y.tab.c"
    break;

  case 42: /* location: tktk_dollarvariable atext tktk_closeE  */
#line 13998 "admstpathYacc.y"
 {/*4 dollar*/
   p_text mytext=adms_text_new(((p_pparse)mypparse)->_transform,"$");
   mytext->_token=adms_slist_reverse((yyvsp[-1]._slist));
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,mytext);
   (yyval._path)->_callback=(void*)location04;
   (yyval._path)->_callbackname="location04.dollar";
 }
#line 15560 "y.tab.c"
    break;

  case 43: /* location: tktk_arobavariable atext tktk_closeE  */
#line 14006 "admstpathYacc.y"
 {/*5 aroba*/
   p_text mytext=adms_text_new(((p_pparse)mypparse)->_transform,"@");
   mytext->_token=adms_slist_reverse((yyvsp[-1]._slist));
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,mytext);
   (yyval._path)->_callback=(void*)location05;
   (yyval._path)->_callbackname="location05.aroba";
 }
#line 15572 "y.tab.c"
    break;

  case 44: /* location: tktk_croixvariable atext tktk_closeE  */
#line 14014 "admstpathYacc.y"
 {/*13 croix*/
   p_text mytext=adms_text_new(((p_pparse)mypparse)->_transform,"#");
   mytext->_token=adms_slist_reverse((yyvsp[-1]._slist));
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,mytext);
   (yyval._path)->_callback=(void*)location13;
   (yyval._path)->_callbackname="location13.croix";
 }
#line 15584 "y.tab.c"
    break;

  case 45: /* location: tktk_croixcroixvariable atext tktk_closeE  */
#line 14022 "admstpathYacc.y"
 {/*12 croixcroix*/
   p_text mytext=adms_text_new(((p_pparse)mypparse)->_transform,"##");
   mytext->_token=adms_slist_reverse((yyvsp[-1]._slist));
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,mytext);
   (yyval._path)->_callback=(void*)location12;
   (yyval._path)->_callbackname="location12.croixcroix";
 }
#line 15596 "y.tab.c"
    break;

  case 46: /* location: quotedstring  */
#line 14030 "admstpathYacc.y"
 {/*9 q*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_text=(yyvsp[0]._text);
   if((adms_slist_length((yyval._path)->_text->_token)==1)&&((yyval._path)->_text->_token->data->_datatypename==admse_admst))
   {
     (yyval._path)->_callback=(void*)location09k;
     (yyval._path)->_callbackname="location09k.q";
   }
   else
   {
     (yyval._path)->_callback=(void*)location09;
     (yyval._path)->_callbackname="location09.q";
   }
 }
#line 15615 "y.tab.c"
    break;

  case 47: /* location: identifier tktk_openE pathroot tktk_closeE  */
#line 14045 "admstpathYacc.y"
 {/*2 function.ident*/
   (yyval._path)=(yyvsp[-3]._path);
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
   (yyval._path)->_callback=(void*)location02;
   (yyval._path)->_callbackname="location02.function.ident";
 }
#line 15626 "y.tab.c"
    break;

  case 48: /* location: tktk_uid tktk_openE pathroot tktk_closeE  */
#line 14052 "admstpathYacc.y"
 {/*20 function.uid*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
   (yyval._path)->_callback=(void*)location20;
   (yyval._path)->_callbackname="location20.function.uid";
 }
#line 15637 "y.tab.c"
    break;

  case 49: /* location: tktk_id tktk_openE pathroot tktk_closeE  */
#line 14059 "admstpathYacc.y"
 {/*21 function.id*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
   (yyval._path)->_callback=(void*)location21;
   (yyval._path)->_callbackname="location21.function.id";
 }
#line 15648 "y.tab.c"
    break;

  case 50: /* location: tktk_sort tktk_openE pathroot tktk_closeE  */
#line 14066 "admstpathYacc.y"
 {/*22 function.sort*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
   (yyval._path)->_callback=(void*)location22;
   (yyval._path)->_callbackname="location22.function.sort";
 }
#line 15659 "y.tab.c"
    break;

  case 51: /* location: tktk_reverse tktk_openE pathroot tktk_closeE  */
#line 14073 "admstpathYacc.y"
 {/*23 function.reverse*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
   (yyval._path)->_callback=(void*)location23;
   (yyval._path)->_callbackname="location23.function.reverse";
 }
#line 15670 "y.tab.c"
    break;

  case 52: /* location: tktk_upper_mcase tktk_openE pathroot tktk_closeE  */
#line 14080 "admstpathYacc.y"
 {/*24 function.uc*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
   (yyval._path)->_callback=(void*)location24;
   (yyval._path)->_callbackname="location24.function.uc";
 }
#line 15681 "y.tab.c"
    break;

  case 53: /* location: tktk_lower_mcase tktk_openE pathroot tktk_closeE  */
#line 14087 "admstpathYacc.y"
 {/*25 function.lc*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
   (yyval._path)->_callback=(void*)location25;
   (yyval._path)->_callbackname="location25.function.lc";
 }
#line 15692 "y.tab.c"
    break;

  case 54: /* location: tktk_count tktk_openE pathroot tktk_closeE  */
#line 14094 "admstpathYacc.y"
 {/*27 function.count*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
   (yyval._path)->_callback=(void*)location27;
   (yyval._path)->_callbackname="location27.function.count";
 }
#line 15703 "y.tab.c"
    break;

  case 55: /* location: tktk_admst tktk_openE tktk_dot tktk_closeE  */
#line 14101 "admstpathYacc.y"
 {/*14 function.admst*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)location14;
   (yyval._path)->_callbackname="location14.function.admst";
 }
#line 15713 "y.tab.c"
    break;

  case 56: /* location: tktk_index tktk_openE pathroot tktk_comma pathroot tktk_closeE  */
#line 14107 "admstpathYacc.y"
 {/*19 function.index*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-3]._path));
   (yyval._path)->_callback=(void*)location19;
   (yyval._path)->_callbackname="location19.function.index";
 }
#line 15725 "y.tab.c"
    break;

  case 57: /* location: tktk_text tktk_openE quotedstring tktk_closeE  */
#line 14115 "admstpathYacc.y"
 {/*26 function.text*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_text=(yyvsp[-1]._text);
   (yyval._path)->_callback=(void*)location26;
   (yyval._path)->_callbackname="location26.function.text";
 }
#line 15736 "y.tab.c"
    break;

  case 58: /* location: tktk_returned tktk_openE quotedstring tktk_closeE  */
#line 14122 "admstpathYacc.y"
 {/*15 function.returned*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_text=(yyvsp[-1]._text);
   (yyval._path)->_callback=(void*)location15;
   (yyval._path)->_callbackname="location15.function.returned";
 }
#line 15747 "y.tab.c"
    break;

  case 59: /* location: tktk_position tktk_openE tktk_dot tktk_closeE  */
#line 14129 "admstpathYacc.y"
 {/*18 function.pos*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)location18;
   (yyval._path)->_callbackname="location18.function.pos";
 }
#line 15757 "y.tab.c"
    break;

  case 60: /* location: tktk_croixstar  */
#line 14135 "admstpathYacc.y"
 {/*130 croixstar*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)location130;
   (yyval._path)->_callbackname="location130.croixstar";
 }
#line 15767 "y.tab.c"
    break;

  case 61: /* location: tktk_ticptr  */
#line 14141 "admstpathYacc.y"
 {/*200 ticptr*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   p_text mytext=adms_text_new(((p_pparse)mypparse)->_transform,"'%p'");
   adms_slist_push(&(mytext->_token),(p_adms)adms_admst_newks(adms_kclone("%p")));
   mytext->_admse=admse__p;
   (yyval._path)->_text=mytext;
   (yyval._path)->_callback=(void*)location200;
   (yyval._path)->_callbackname="location200.ticptr";
 }
#line 15781 "y.tab.c"
    break;

  case 62: /* quotedstring: tktk_oquote atext tktk_cquote  */
#line 14153 "admstpathYacc.y"
 {/*0*/
   p_text mytext=adms_text_new(((p_pparse)mypparse)->_transform,"qtext");
   mytext->_token=adms_slist_reverse((yyvsp[-1]._slist));
   if(adms_slist_length(mytext->_token)==1)
   {
     if(mytext->_token->data->_datatypename==admse_path)
       mytext->_admse=admse__path;
     else if(mytext->_token->data->_datatypename==admse_admst)
       mytext->_admse=ns_strtoe(((p_admst)mytext->_token->data)->_item.s);
   }
   (yyval._text)=mytext;
 }
#line 15798 "y.tab.c"
    break;

  case 63: /* quotedstring: tktk_oquote tktk_cquote  */
#line 14166 "admstpathYacc.y"
 {/*1*/
   p_text mytext=adms_text_new(((p_pparse)mypparse)->_transform,"");
   adms_slist_push(&(mytext->_token),(p_adms)adms_admst_newks(adms_kclone("")));
   (yyval._text)=mytext;
 }
#line 15808 "y.tab.c"
    break;

  case 64: /* atext: atextitem  */
#line 14174 "admstpathYacc.y"
 {/*0*/
   (yyval._slist)=NULL;
   adms_slist_push(&(yyval._slist),(p_adms)(yyvsp[0]._path));
 }
#line 15817 "y.tab.c"
    break;

  case 65: /* atext: atext atextitem  */
#line 14179 "admstpathYacc.y"
 {/*1*/
   (yyval._slist)=(yyvsp[-1]._slist);
   adms_slist_push(&(yyval._slist),(p_adms)(yyvsp[0]._path));
 }
#line 15826 "y.tab.c"
    break;

  case 66: /* atextitem: tktk_cr  */
#line 14186 "admstpathYacc.y"
 {/*0*/
   (yyval._path)=(p_path)adms_admst_newks(adms_kclone("\n"));
 }
#line 15834 "y.tab.c"
    break;

  case 67: /* atextitem: tktk_lf  */
#line 14190 "admstpathYacc.y"
 {/*1*/
   (yyval._path)=(p_path)adms_admst_newks(adms_kclone("\r"));
 }
#line 15842 "y.tab.c"
    break;

  case 68: /* atextitem: tktk_tab  */
#line 14194 "admstpathYacc.y"
 {/*2*/
   (yyval._path)=(p_path)adms_admst_newks(adms_kclone("\t"));
 }
#line 15850 "y.tab.c"
    break;

  case 69: /* atextitem: tktk_anytext  */
#line 14198 "admstpathYacc.y"
 {/*3*/
   (yyval._path)=(p_path)adms_admst_newks(adms_knclone(((p_pparse)mypparse)->_tkstart,((p_pparse)mypparse)->_tklen));
 }
#line 15858 "y.tab.c"
    break;

  case 70: /* atextitem: tktk_percents  */
#line 14202 "admstpathYacc.y"
 {/*4*/
   (yyval._path)=(p_path)adms_text_new(((p_pparse)mypparse)->_transform,"%s");
   ((p_text)(yyval._path))->_admse=admse__s;
 }
#line 15867 "y.tab.c"
    break;

  case 71: /* atextitem: tktk_dollarvariable atext tktk_closeE  */
#line 14207 "admstpathYacc.y"
 {/*5*/
   (yyval._path)=(p_path)adms_text_new(((p_pparse)mypparse)->_transform,"$");
   ((p_text)(yyval._path))->_token=adms_slist_reverse((yyvsp[-1]._slist));
 }
#line 15876 "y.tab.c"
    break;

  case 72: /* atextitem: tktk_kdollarvariable  */
#line 14212 "admstpathYacc.y"
 {/*6*/
   char* mytvalue=adms_knclone(((p_pparse)mypparse)->_tkstart,((p_pparse)mypparse)->_tklen);
   (yyval._path)=(p_path)adms_text_new(((p_pparse)mypparse)->_transform,"$");
   adms_slist_push(&(((p_text)(yyval._path))->_token),(p_adms)adms_admst_newks(mytvalue));
 }
#line 15886 "y.tab.c"
    break;

  case 73: /* atextitem: tktk_percent pathroot tktk_closeE  */
#line 14218 "admstpathYacc.y"
 {/*7*/
   (yyval._path)=(yyvsp[-1]._path);
 }
#line 15894 "y.tab.c"
    break;

  case 74: /* condition: tktk_openCond expression tktk_closeCond  */
#line 14224 "admstpathYacc.y"
 {/*0*/
   (yyval._path)=(yyvsp[-1]._path);
 }
#line 15902 "y.tab.c"
    break;

  case 75: /* expression: binaryor  */
#line 14230 "admstpathYacc.y"
 {/*0*/
   (yyval._path)=(yyvsp[0]._path);
 }
#line 15910 "y.tab.c"
    break;

  case 76: /* expression: pathroot  */
#line 14234 "admstpathYacc.y"
 {/*1*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)expression01;
   (yyval._path)->_callbackname="expression01";
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[0]._path));
 }
#line 15921 "y.tab.c"
    break;

  case 77: /* binaryor: binaryand  */
#line 14243 "admstpathYacc.y"
 {/*0*/
   (yyval._path)=(yyvsp[0]._path);
 }
#line 15929 "y.tab.c"
    break;

  case 78: /* binaryor: binaryor tktk_or binaryand  */
#line 14247 "admstpathYacc.y"
 {/*1*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)binaryor;
   (yyval._path)->_callbackname="binaryor";
   adms_slist_push(&(yyval._path)->_b,(p_adms)(yyvsp[0]._path));
   adms_slist_push(&(yyval._path)->_b,(p_adms)(yyvsp[-2]._path));
 }
#line 15941 "y.tab.c"
    break;

  case 79: /* binaryand: unary  */
#line 14257 "admstpathYacc.y"
 {/*0*/
   (yyval._path)=(yyvsp[0]._path);
 }
#line 15949 "y.tab.c"
    break;

  case 80: /* binaryand: binaryand tktk_and unary  */
#line 14261 "admstpathYacc.y"
 {/*1*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)binaryand;
   (yyval._path)->_callbackname="binaryand";
   adms_slist_push(&(yyval._path)->_b,(p_adms)(yyvsp[0]._path));
   adms_slist_push(&(yyval._path)->_b,(p_adms)(yyvsp[-2]._path));
 }
#line 15961 "y.tab.c"
    break;

  case 81: /* unary: atomic  */
#line 14271 "admstpathYacc.y"
 {/*0*/
   (yyval._path)=(yyvsp[0]._path);
 }
#line 15969 "y.tab.c"
    break;

  case 82: /* unary: tktk_not atomic  */
#line 14275 "admstpathYacc.y"
 {/*1*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)unary00;
   (yyval._path)->_callbackname="unary00";
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[0]._path));
 }
#line 15980 "y.tab.c"
    break;

  case 83: /* atomic: tktk_openE binaryor tktk_closeE  */
#line 14284 "admstpathYacc.y"
 {/*3 groupage*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)atomicgroupage;
   (yyval._path)->_callbackname="atomicgroupage";
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
 }
#line 15991 "y.tab.c"
    break;

  case 84: /* atomic: pathroot tktk_equal pathroot  */
#line 14291 "admstpathYacc.y"
 {/*8 eq*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)atomiceq;
   (yyval._path)->_callbackname="atomiceq";
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[0]._path));
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-2]._path));
 }
#line 16003 "y.tab.c"
    break;

  case 85: /* atomic: pathroot tktk_notequal pathroot  */
#line 14299 "admstpathYacc.y"
 {/*9 ne*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)atomicne;
   (yyval._path)->_callbackname="atomicne";
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[0]._path));
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-2]._path));
 }
#line 16015 "y.tab.c"
    break;

  case 86: /* atomic: pathroot tktk_lt pathroot  */
#line 14307 "admstpathYacc.y"
 {/*10 lt*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)atomiclt;
   (yyval._path)->_callbackname="atomiclt";
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[0]._path));
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-2]._path));
 }
#line 16027 "y.tab.c"
    break;

  case 87: /* atomic: pathroot tktk_gt pathroot  */
#line 14315 "admstpathYacc.y"
 {/*11 gt*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)atomicgt;
   (yyval._path)->_callbackname="atomicgt";
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[0]._path));
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-2]._path));
 }
#line 16039 "y.tab.c"
    break;

  case 88: /* atomic: tktk_nilled tktk_openE pathroot tktk_closeE  */
#line 14323 "admstpathYacc.y"
 {/*0 nilled*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)atomicnilled;
   (yyval._path)->_callbackname="atomicnilled";
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
 }
#line 16050 "y.tab.c"
    break;

  case 89: /* atomic: tktk_exists tktk_openE pathroot tktk_closeE  */
#line 14330 "admstpathYacc.y"
 {/*1 exists*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)atomicexists;
   (yyval._path)->_callbackname="atomicexists";
   adms_slist_push(&(yyval._path)->_u,(p_adms)(yyvsp[-1]._path));
 }
#line 16061 "y.tab.c"
    break;

  case 90: /* atomic: tktk_isdefault tktk_openE tktk_ident tktk_closeE  */
#line 14337 "admstpathYacc.y"
 {/*2 isdefault*/
   (yyval._path)=BASICSTRING((p_pparse)mypparse,adms_knclone(((p_pparse)mypparse)->_tkstart,((p_pparse)mypparse)->_tklen));
   (yyval._path)->_callback=(void*)atomicisdefault;
   (yyval._path)->_callbackname="atomicisdefault";
 }
#line 16071 "y.tab.c"
    break;

  case 91: /* atomic: tktk_true tktk_openE tktk_closeE  */
#line 14343 "admstpathYacc.y"
 {/*5 true*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)atomictrue;
   (yyval._path)->_callbackname="atomictrue";
 }
#line 16081 "y.tab.c"
    break;

  case 92: /* atomic: tktk_false tktk_openE tktk_closeE  */
#line 14349 "admstpathYacc.y"
 {/*6 false*/
   (yyval._path)=adms_path_new(((p_pparse)mypparse)->_transform,NULL);
   (yyval._path)->_callback=(void*)atomicfalse;
   (yyval._path)->_callbackname="atomicfalse";
 }
#line 16091 "y.tab.c"
    break;


#line 16095 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (mypparse, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, mypparse);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, mypparse);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (mypparse, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, mypparse);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, mypparse);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 14356 "admstpathYacc.y"

static const char* tparsecb (p_pparse mypparse)
{
  const char* t=mypparse->_position;
  mypparse->_tkstart=t;
  if(0) {}
  else if(*t=='\''&&INSIDEPATH)
  {
    adms_slist_pull(&globalctxt);
    t+=1, mypparse->_tkid= (admse) tktk_cquote;
  }
  else if(*t=='%')
  {
    if(*(t+1)=='\0')
      t+=1, mypparse->_tkid= (admse) tktk_anytext;
    else if(*(t+1)=='s')
      t+=2, mypparse->_tkid= (admse) tktk_percents;
    else if(*(t+1)=='%')
    {
      mypparse->_tkstart=t+1;
      t+=2, mypparse->_tkid= (admse) tktk_anytext;
    }
    else if(*(t+1)=='(')
    {
      paren++; adms_slist_push(&parenidx,(p_adms)(long)paren); SETPATH
      mypparse->_tkstart=t+2;
      t+=2, mypparse->_tkid= (admse) tktk_percent;
    }
    else
      t+=2, mypparse->_tkid= (admse) tktk_anytext;
  }
  else if(*t=='\\')
  {
    if(*(t+1)=='\0')
      t+=1, mypparse->_tkid= (admse) tktk_anytext;
    if(*(t+1)=='n')
      t+=2, mypparse->_tkid= (admse) tktk_cr;
    else if(*(t+1)=='r')
      t+=2, mypparse->_tkid= (admse) tktk_cr;
    else if(*(t+1)=='t')
      t+=2, mypparse->_tkid= (admse) tktk_tab;
    else
    {
      mypparse->_tkstart=t+1;
      t+=2, mypparse->_tkid= (admse) tktk_anytext;
    }
  }
  else if(*t=='$')
  {
    if(*(t+1)=='\0')
      t+=1, mypparse->_tkid= (admse) tktk_anytext;
    if(*(t+1)=='(')
    {
      paren++; adms_slist_push(&parenidx,(p_adms)(long)paren); SETTEXT
      mypparse->_tkstart=t+2;
      t+=2, mypparse->_tkid= (admse) tktk_dollarvariable;
    }
    else
    {
      mypparse->_tkstart=t+1;
      t++;
      while(*t&&(isalnum(*t)||*t=='_'))
        t++;
      mypparse->_tkid= (admse) tktk_kdollarvariable;
    }
  }
  else if(ISTEXT&&(*t==')'))
  {
    if(PARENMATCH)
    {
      t+=1, mypparse->_tkid= (admse) tktk_closeE, adms_slist_pull(&parenidx);
      adms_slist_pull(&globalctxt);
    }
    else
      t+=1, mypparse->_tkid= (admse) tktk_anytext;
    paren--;
  }
  else
  {
    if(INSIDEPATH)
    {
      if(ISTEXT) while(*t&&(*t!=')')&&(*t!='\0')&&(*t!='%')&&(*t!='\\')&&(*t!='$')&&(*t!='\''))
      {
        if(*t=='(') paren++;
        t++;
      }
      else if(ISTIC) while(*t&&(*t!='\0')&&(*t!='%')&&(*t!='\\')&&(*t!='$')&&(*t!='\''))
      {
        t++;
      }
      else
        adms_message_fatal(("%s:'%s' unexpected error in apath parser - please report to r29173@users.sourceforge.net\n",adms_transform_uid(mypparse->_transform),mypparse->_value))
    }
    else
    {
      if(ISTEXT) while(*t&&(*t!=')')&&(*t!='\0')&&(*t!='%')&&(*t!='\\')&&(*t!='$'))
      {
        if(*t=='(') paren++;
        t++;
      }
      else if(ISTIC) while(*t&&(*t!='\0')&&(*t!='%')&&(*t!='\\')&&(*t!='$'))
      {
        t++;
      }
      else
        adms_message_fatal(("%s:'%s' unexpected error in apath parser - please report to r29173@users.sourceforge.net\n",adms_transform_uid(mypparse->_transform),mypparse->_value))
    }
    mypparse->_tkid= (admse) tktk_anytext;
  }
  mypparse->_tklen=(int)(long)(t-mypparse->_tkstart);
  return t;
}
static int admstpathlex (p_pparse mypparse)
{
  const char* t=mypparse->_position;
  const char* tstart;
  if(*t=='\0')
    return 0;
  if(goto_atext)
  {
    goto_atext=0;
    return tktk_goto_atext;
  }
  while(*t&&isspace(*t)) t++;
  tstart=t;
  if(!strncmp(t,"\'%p\'",4)&&!isalpha(*(t+4)))
    t+=4, mypparse->_tkid= (admse) tktk_ticptr;
  else if(!ISPATH)
    t=tparsecb(mypparse);
  else if(!strncmp(t,"(",1))
  {
    t+=1, mypparse->_tkid= (admse) tktk_openE;
    paren++;
  }
  else if(!strncmp(t,")",1))
  {
    if(PARENMATCH)
    {
      t+=1, mypparse->_tkid= (admse) tktk_closeE, adms_slist_pull(&parenidx);
      adms_slist_pull(&globalctxt);
    }
    else
      t+=1, mypparse->_tkid= (admse) tktk_closeE;
    paren--;
  }
  else if(*t=='$'&&*(t+1)=='(')
  {
    t++;
    t++;
    paren++; adms_slist_push(&parenidx,(p_adms)(long)paren); SETTEXT
    mypparse->_tkid= (admse) tktk_dollarvariable;
  }
  else if(*t=='$')
  {
    t++;
    while(isalnum(*t)||*t=='_') t++;
    mypparse->_tkstart=tstart+1;
    mypparse->_tklen=(int)(long)(t-(tstart+1));
    mypparse->_tkid= (admse) tktk_kdollarvariable;
  }
  else if(*t=='@'&&*(t+1)=='(')
  {
    t++;
    t++;
    paren++; adms_slist_push(&parenidx,(p_adms)(long)paren); SETTEXT
    mypparse->_tkid= (admse) tktk_arobavariable;
  }
  else if(*t=='@')
  {
    t++;
    while(isalnum(*t)||*t=='_') t++;
    mypparse->_tkstart=tstart+1;
    mypparse->_tklen=(int)(long)(t-(tstart+1));
    mypparse->_tkid= (admse) tktk_karobavariable;
  }
  else if(*t=='#'&&*(t+1)=='#'&&*(t+2)=='(')
  {
    t++;
    t++;
    t++;
    paren++; adms_slist_push(&parenidx,(p_adms)(long)paren); SETTEXT
    mypparse->_tkid= (admse) tktk_croixcroixvariable;
  }
  else if(*t=='#'&&*(t+1)=='*')
  {
    t++;
    t++;
    while(isalnum(*t)||*t=='_') t++;
    mypparse->_tkstart=tstart+1;
    mypparse->_tklen=(int)(long)(t-(tstart+1));
    mypparse->_tkid= (admse) tktk_croixstar;
  }
  else if(*t=='#'&&*(t+1)=='#')
  {
    t++;
    t++;
    while(isalnum(*t)||*t=='_') t++;
    mypparse->_tkstart=tstart+1;
    mypparse->_tklen=(int)(long)(t-(tstart+1));
    mypparse->_tkid= (admse) tktk_kcroixcroixvariable;
  }
  else if(*t=='#'&&*(t+1)=='(')
  {
    t++;
    t++;
    paren++; adms_slist_push(&parenidx,(p_adms)(long)paren); SETTEXT
    mypparse->_tkid= (admse) tktk_croixvariable;
  }
  else if(*t=='#')
  {
    t++;
    while(isalnum(*t)||*t=='_') t++;
    mypparse->_tkstart=tstart+1;
    mypparse->_tklen=(int)(long)(t-(tstart+1));
    mypparse->_tkid= (admse) tktk_kcroixvariable;
  }
  else if(*t=='\'')
  {
    SETTIC
    t+=1, mypparse->_tkid= (admse) tktk_oquote;
  }
  else if(!strncmp(t,"!=",2))
    t+=2, mypparse->_tkid= (admse) tktk_notequal;
  else if(!strncmp(t,">",1))
    t+=1, mypparse->_tkid= (admse) tktk_gt;
  else if(!strncmp(t,"<",1))
    t+=1, mypparse->_tkid= (admse) tktk_lt;
  else if(!strncmp(t,"*",1))
    t+=1, mypparse->_tkid= (admse) tktk_star;
  else if(!strncmp(t,"++",2))
    t+=2, mypparse->_tkid= (admse) tktk_incrp;
  else if(!strncmp(t,"--",2))
    t+=2, mypparse->_tkid= (admse) tktk_incrm;
  else if(!strncmp(t,"+",1))
    t+=1, mypparse->_tkid= (admse) tktk_addp;
  else if(!strncmp(t,":",1))
    t+=1, mypparse->_tkid= (admse) tktk_column;
  else if(!strncmp(t,",",1))
    t+=1, mypparse->_tkid= (admse) tktk_comma;
  else if(!strncmp(t,"|",1))
    t+=1, mypparse->_tkid= (admse) tktk_bar;
  else if(!strncmp(t,"-",1))
    t+=1, mypparse->_tkid= (admse) tktk_addm;
  else if(!strncmp(t,"..",2))
    t+=2, mypparse->_tkid= (admse) tktk_dotdot;
  else if(!strncmp(t,".",1))
    t+=1, mypparse->_tkid= (admse) tktk_dot;
  else if(!strncmp(t,"/",1))
    t+=1, mypparse->_tkid= (admse) tktk_slash;
  else if(!strncmp(t,"=",1))
    t+=1, mypparse->_tkid= (admse) tktk_equal;
  else if(!strncmp(t,"[",1))
    t+=1, mypparse->_tkid= (admse) tktk_openCond;
  else if(!strncmp(t,"]",1))
    t+=1, mypparse->_tkid= (admse) tktk_closeCond;
  else if(!strncmp(t,"admst",5)&&!isalpha(*(t+5)))
    t+=5, mypparse->_tkid= (admse) tktk_admst;
  else if(!strncmp(t,"and",3)&&!isalpha(*(t+3)))
    t+=3, mypparse->_tkid= (admse) tktk_and;
  else if(!strncmp(t,"count",5)&&!isalpha(*(t+5)))
    t+=5, mypparse->_tkid= (admse) tktk_count;
  else if(!strncmp(t,"exists",6)&&!isalpha(*(t+6)))
    t+=6, mypparse->_tkid= (admse) tktk_exists;
  else if(!strncmp(t,"false",5)&&!isalpha(*(t+5)))
    t+=5, mypparse->_tkid= (admse) tktk_false;
  else if(!strncmp(t,"id",2)&&!isalpha(*(t+2)))
    t+=2, mypparse->_tkid= (admse) tktk_id;
  else if(!strncmp(t,"index",5)&&!isalpha(*(t+5)))
    t+=5, mypparse->_tkid= (admse) tktk_index;
  else if(!strncmp(t,"isdefault",9)&&!isalpha(*(t+9)))
    t+=9, mypparse->_tkid= (admse) tktk_isdefault;
  else if(!strncmp(t,"lower-case",10)&&!isalpha(*(t+10)))
    t+=10, mypparse->_tkid= (admse) tktk_lower_mcase;
  else if(!strncmp(t,"nilled",6)&&!isalpha(*(t+6)))
    t+=6, mypparse->_tkid= (admse) tktk_nilled;
  else if(!strncmp(t,"not",3)&&!isalpha(*(t+3)))
    t+=3, mypparse->_tkid= (admse) tktk_not;
  else if(!strncmp(t,"or",2)&&!isalpha(*(t+2)))
    t+=2, mypparse->_tkid= (admse) tktk_or;
  else if(!strncmp(t,"position",8)&&!isalpha(*(t+8)))
    t+=8, mypparse->_tkid= (admse) tktk_position;
  else if(!strncmp(t,"returned",8)&&!isalpha(*(t+8)))
    t+=8, mypparse->_tkid= (admse) tktk_returned;
  else if(!strncmp(t,"reverse",7)&&!isalpha(*(t+7)))
    t+=7, mypparse->_tkid= (admse) tktk_reverse;
  else if(!strncmp(t,"sort",4)&&!isalpha(*(t+4)))
    t+=4, mypparse->_tkid= (admse) tktk_sort;
  else if(!strncmp(t,"text",4)&&!isalpha(*(t+4)))
    t+=4, mypparse->_tkid= (admse) tktk_text;
  else if(!strncmp(t,"true",4)&&!isalpha(*(t+4)))
    t+=4, mypparse->_tkid= (admse) tktk_true;
  else if(!strncmp(t,"uid",3)&&!isalpha(*(t+3)))
    t+=3, mypparse->_tkid= (admse) tktk_uid;
  else if(!strncmp(t,"upper-case",10)&&!isalpha(*(t+10)))
    t+=10, mypparse->_tkid= (admse) tktk_upper_mcase;
  else if(isalpha(*t))
  {
    while(isalnum(*t)||*t=='_'||*t==':') t++;
    mypparse->_tkid= (admse) tktk_ident;
    mypparse->_tkstart=tstart;
    mypparse->_tklen=(int)(long)(t-tstart);
  }
  else if(isdigit(*t))
  {
    while(isdigit(*t)) t++;
    if(*t=='.')
    {
      t++;
      while(isdigit(*t)) t++;
      mypparse->_tkid= (admse) tktk_real;
      mypparse->_tkstart=tstart;
      mypparse->_tklen=(int)(long)(t-tstart);
    }
    else
    {
      mypparse->_tkid= (admse) tktk_integer;
      mypparse->_tkstart=tstart;
      mypparse->_tklen=(int)(long)(t-tstart);
    }
  }
  else
  {
    if(*t=='\0')
      return 0;
    adms_message_fatal(("%s: invalid path - unexpected character: %s\n",
    adms_transform_uid(mypparse->_transform),
    mypparse->_value))
  }
  mypparse->_position=t;
  return mypparse->_tkid;
}
p_path pparse (p_transform mytransform,const char* aname,const char* avalue)
{
  p_path mypath;
  p_pparse mypparse=adms_pparse_new(mytransform,aname,avalue);
  goto_atext=0;
  SETPATH
  globalignorequote=0;
  if(*avalue)
  {
    mypparse->_position=avalue;
    admstpathparse (mypparse);
    mypath=mypparse->_path;
    mypath->_aname=adms_kclone(aname);
    mypath->_avalue=avalue?adms_kclone(avalue):adms_kclone("");
  }
  else
  {
    mypath=NULL;
    adms_message_fatal_continue(("invalid path \"%s\"\n",mypparse->_value))
    adms_message_fatal(("see %s\n",adms_transform_uid(mypparse->_transform)))
  }
  adms_slist_pull(&globalctxt);
  adms_pparse_free(mypparse);
  return mypath;
}
p_text tparse (p_ktransform mytransform, const char* aname, const char* avalue)
{
  p_text mytext;
  if(!avalue)
    mytext=adms_text_new(mytransform,avalue);
  else if(*avalue=='\0')
  {
    p_text mytext=adms_text_new(mytransform,avalue);
    adms_slist_push(&(mytext->_token),(p_adms)adms_admst_newks(adms_kclone("")));
    return mytext;
  }
  else
  {
    p_pparse mypparse=adms_pparse_new(mytransform,aname,avalue);
    SETTIC
    goto_atext=1;
    globalignorequote=1;
    mypparse->_position=avalue;
    admstpathparse (mypparse);
    mytext=mypparse->_text;
    adms_pparse_free(mypparse);
    mytext->_value=adms_kclone(avalue);
    adms_slist_pull(&globalctxt);
  }
  mytext->_admse=ns_strtoe(avalue);
  if((adms_slist_length(mytext->_token)==1)&&(mytext->_token->data->_datatypename==admse_path))
    mytext->_admse=admse__path;
  else if(!strcmp(avalue,"%p"))
    mytext->_admse=admse__p;
  mytext->_aname=adms_kclone(aname);
  return mytext;
}
int apath_main (int argc,char **argv)
{
  int argci;
  int doatext=0;
  char*avalue=(argc==1)?"a/b/c|c|c|c":argv[1];
  for(argci=1;argci<argc;argci++)
  {
#if YYDEBUG
    admstpathdebug=admstpathdebug||!strcmp("-d",argv[argci]);
#endif
    doatext=!strcmp("-t",argv[argci]);
  }
  printf("parsing=%s\n",doatext?"text":"apath");
  goto_atext=doatext;
  printf("%s \"%s\"\n",argv[0],avalue);
  rootnew(adms_admsmain_new("admsmain"));
  if(doatext)
    dbtext(tparse(adms_transform_new("<stdin>","<stdin>",0,"*",NULL),"input:text",avalue));
  else
  {
    char*aname="stdin";
    p_pparse mypparse=adms_pparse_new(adms_transform_new("<stdin>","<stdin>",0,"*",NULL),aname,avalue);
    mypparse->_position=avalue;
    SETPATH
    globalignorequote=0;
    admstpathparse (mypparse);
    printf("<p id=\"%s\">",avalue);
    mypparse->_path->_aname=adms_kclone(aname);
    postpath(mypparse->_path);
    dbpath(mypparse->_path);
    printf("</p>\n");
  }
  return 0;
}
