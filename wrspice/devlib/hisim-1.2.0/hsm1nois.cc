
/*========================================================================*
 *                                                                        *
 *  Distributed by Whiteley Research Inc., Sunnyvale, California, USA     *
 *                       http://wrcad.com                                 *
 *  Copyright (C) 2017 Whiteley Research Inc., all rights reserved.       *
 *  Author: Stephen R. Whiteley, except as indicated.                     *
 *                                                                        *
 *  As fully as possible recognizing licensing terms and conditions       *
 *  imposed by earlier work from which this work was derived, if any,     *
 *  this work is released under the Apache License, Version 2.0 (the      *
 *  "License").  You may not use this file except in compliance with      *
 *  the License, and compliance with inherited licenses which are         *
 *  specified in a sub-header below this one if applicable.  A copy       *
 *  of the License is provided with this distribution, or you may         *
 *  obtain a copy of the License at                                       *
 *                                                                        *
 *        http://www.apache.org/licenses/LICENSE-2.0                      *
 *                                                                        *
 *  See the License for the specific language governing permissions       *
 *  and limitations under the License.                                    *
 *                                                                        *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,      *
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES      *
 *   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-        *
 *   INFRINGEMENT.  IN NO EVENT SHALL WHITELEY RESEARCH INCORPORATED      *
 *   OR STEPHEN R. WHITELEY BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER     *
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      *
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE       *
 *   USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 *                                                                        *
 *========================================================================*
 *               XicTools Integrated Circuit Design System                *
 *                                                                        *
 * WRspice Circuit Simulation and Analysis Tool:  Device Library          *
 *                                                                        *
 *========================================================================*
 $Id:$
 *========================================================================*/

/***********************************************************************
 HiSIM (Hiroshima University STARC IGFET Model)
 Copyright (C) 2003 STARC

 VERSION : HiSIM 1.2.0
 FILE : hsm1noi.c of HiSIM 1.2.0

 April 9, 2003 : released by STARC Physical Design Group
***********************************************************************/

#include <stdio.h>
#include "hsm1defs.h"
#include "noisdefs.h"

#define HSM1nextModel      next()
#define HSM1nextInstance   next()
#define HSM1instances      inst()
#define HSM1name GENname
#define MAX SPMAX
#define NOISEAN sNOISEAN
#define Nintegrate(a, b, c, d) (d)->integrate(a, b, c)
#define NstartFreq JOBac.fstart()

/*
 Channel thermal and flicker noises are calculated based on the value
 of model->HSM1_noise.
 If model->HSM1_noise = 1,
    Channel thermal noise = SPICE2 model
    Flicker noise         = SPICE2 model
 If model->HSM1_noise = 2,
    Channel thermal noise = HiSIM1 model corresponding to BSIM3 model
    Flicker noise         = HiSIM1 model
 If model->HSM1_noise = 3,
    Channel thermal noise = SPICE2 model 
    Flicker noise         = HiSIM1 model
 If model->HSM1_noise = 4,
    Channel thermal noise = HiSIM1 model corresponding to BSIM3 model
    Flicker noise         = SPICE2 model
 If model->HSM1_noise = 5,
    Channel thermal noise = NONE
    Flicker noise         = HiSIM1 model
*/


int
HSM1dev::noise(int mode, int operation, sGENmodel *genmod, sCKT *ckt,
    sNdata *data, double *OnDens)
{
    sHSM1model *model = static_cast<sHSM1model*>(genmod);
    sHSM1instance *here;

  char hsm1name[N_MXVLNTH];
  double tempOnoise;
  double tempInoise;
  double noizDens[HSM1NSRCS];
  double lnNdens[HSM1NSRCS];
  /*register*/ int /*error,*/ i;

  /* define the names of the noise sources */
  static const char * HSM1nNames[HSM1NSRCS] = {
    /* Note that we have to keep the order
       consistent with the index definitions 
       in hsm1defs.h */
    ".rd",              /* noise due to rd */
    ".rs",              /* noise due to rs */
    ".id",              /* noise due to id */
    ".1ovf",            /* flicker (1/f) noise */
    ""                  /* total transistor noise */
  };
  
  for ( ;model != NULL; model = model->HSM1nextModel ) {
    for ( here = model->HSM1instances; here != NULL;
          here = here->HSM1nextInstance ) {
      switch (operation) {
      case N_OPEN:
        /* see if we have to to produce a summary report */
        /* if so, name all the noise generators */
          
        if (((NOISEAN*)ckt->CKTcurJob)->NStpsSm != 0) {
          switch (mode) {
          case N_DENS:
            for ( i = 0; i < HSM1NSRCS; i++ ) { 
              (void) snprintf(hsm1name, sizeof(hsm1name), "onoise.%s%s", 
                             (char *)here->HSM1name, HSM1nNames[i]);
/* SRW
              data->namelist = 
                (IFuid *) trealloc((char *) data->namelist,
                                   (data->numPlots + 1) * sizeof(IFuid));
              if (!data->namelist)
                return(E_NOMEM);
              (*(SPfrontEnd->IFnewUid)) 
                (ckt, &(data->namelist[data->numPlots++]),
                 (IFuid) NULL, hsm1name, UID_OTHER, (GENERIC **) NULL);
*/
                Realloc(&data->namelist, data->numPlots+1,
                    data->numPlots);
                ckt->newUid(&data->namelist[data->numPlots++],
                    0, hsm1name, UID_OTHER);

            }
            break;
          case INT_NOIZ:
            for ( i = 0; i < HSM1NSRCS; i++ ) {
              (void) snprintf(hsm1name, sizeof(hsm1name), "onoise_total.%s%s", 
                             (char *)here->HSM1name, HSM1nNames[i]);
/* SRW
              data->namelist = 
                (IFuid *) trealloc((char *) data->namelist,
                                   (data->numPlots + 1) * sizeof(IFuid));
              if (!data->namelist)
                return(E_NOMEM);
              (*(SPfrontEnd->IFnewUid)) 
                (ckt, &(data->namelist[data->numPlots++]),
                 (IFuid) NULL, hsm1name, UID_OTHER, (GENERIC **) NULL);
*/
                Realloc(&data->namelist, data->numPlots+2,
                    data->numPlots);
                ckt->newUid(&data->namelist[data->numPlots++],
                    0, hsm1name, UID_OTHER);
              
              (void) snprintf(hsm1name, sizeof(hsm1name), "inoise_total.%s%s", 
                             (char *)here->HSM1name, HSM1nNames[i]);
/* SRW
              data->namelist = 
                (IFuid *) trealloc((char *) data->namelist,
                                   (data->numPlots + 1) * sizeof(IFuid));
              if (!data->namelist)
                return(E_NOMEM);
              (*(SPfrontEnd->IFnewUid)) 
                (ckt, &(data->namelist[data->numPlots++]),
                 (IFuid) NULL, hsm1name, UID_OTHER, (GENERIC **)NULL);
*/
                ckt->newUid(&data->namelist[data->numPlots++],
                    0, hsm1name, UID_OTHER);

            }
            break;
          }
        }
        break;
      case N_CALC:
        switch (mode) {
        case N_DENS:
          NevalSrc(&noizDens[HSM1RDNOIZ], &lnNdens[HSM1RDNOIZ], 
                   ckt, THERMNOISE,
                   here->HSM1dNodePrime, here->HSM1dNode,
                   here->HSM1drainConductance);
          
          NevalSrc(&noizDens[HSM1RSNOIZ], &lnNdens[HSM1RSNOIZ], 
                   ckt, THERMNOISE,
                   here->HSM1sNodePrime, here->HSM1sNode,
                   here->HSM1sourceConductance);

          switch( model->HSM1_noise ) {
            double I;
          case 1:
          case 3:
            I = here->HSM1_gm + here->HSM1_gds + here->HSM1_gmbs;
            I *= (I < 0.0) ? -1.0 : 1.0;
            I *= 2.0/3.0;
            NevalSrc(&noizDens[HSM1IDNOIZ], &lnNdens[HSM1IDNOIZ], 
                     ckt, THERMNOISE, 
                     here->HSM1dNodePrime, here->HSM1sNodePrime, I);
            break;
          case 2:
          case 4:
            I = -1.0 * (here->HSM1_qg + here->HSM1_qb)
              / (here->HSM1_weff * here->HSM1_leff);
            I *= (I < 0.0) ? -1.0 : 1.0;
            I *= here->HSM1_mu;
            NevalSrc(&noizDens[HSM1IDNOIZ], &lnNdens[HSM1IDNOIZ], 
                     ckt, THERMNOISE, 
                     here->HSM1dNodePrime, here->HSM1sNodePrime, I);
            break;
          case 5:
            NevalSrc(&noizDens[HSM1IDNOIZ], &lnNdens[HSM1IDNOIZ], 
                     ckt, THERMNOISE, 
                     here->HSM1dNodePrime, here->HSM1sNodePrime, 0.0);
            break;
          }
          NevalSrc(&noizDens[HSM1FLNOIZ], (double*) NULL,
                   ckt, N_GAIN, 
                   here->HSM1dNodePrime, here->HSM1sNodePrime, 
                   (double) 0.0);
          
          /* flicker noise */
          switch ( model->HSM1_noise ) {
          case 1:
          case 4: /* SPICE2 model */
            noizDens[HSM1FLNOIZ] *= model->HSM1_kf
              * exp(model->HSM1_af * log(MAX(FABS(here->HSM1_ids), N_MINLOG)))
              / (pow(data->freq, model->HSM1_ef) * here->HSM1_leff
                 * here->HSM1_leff * (3.453133e-11 / model->HSM1_tox));
            /*                        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~cox  */
            break;
          case 2:
          case 3:
          case 5:
            /* from HiSIM */
            noizDens[HSM1FLNOIZ] *= here->HSM1_nfc / data->freq; 
            break;
          }
          
          lnNdens[HSM1FLNOIZ] = log(MAX(noizDens[HSM1FLNOIZ], N_MINLOG));
          
          noizDens[HSM1TOTNOIZ] = noizDens[HSM1RDNOIZ] + noizDens[HSM1RSNOIZ]
            + noizDens[HSM1IDNOIZ] + noizDens[HSM1FLNOIZ];
          lnNdens[HSM1TOTNOIZ] = log(MAX(noizDens[HSM1TOTNOIZ], N_MINLOG));
          
          *OnDens += noizDens[HSM1TOTNOIZ];
          
          if ( data->delFreq == 0.0 ) {
            /* if we haven't done any previous 
               integration, we need to initialize our
               "history" variables.
            */
            
            for ( i = 0; i < HSM1NSRCS; i++ ) 
              here->HSM1nVar[LNLSTDENS][i] = lnNdens[i];
            
            /* clear out our integration variables
               if it's the first pass
            */
            if (data->freq == ((NOISEAN*) ckt->CKTcurJob)->NstartFreq) {
              for (i = 0; i < HSM1NSRCS; i++) {
                here->HSM1nVar[OUTNOIZ][i] = 0.0;
                here->HSM1nVar[INNOIZ][i] = 0.0;
              }
            }
          }
          else {
            /* data->delFreq != 0.0,
               we have to integrate.
            */
            for ( i = 0; i < HSM1NSRCS; i++ ) {
              if ( i != HSM1TOTNOIZ ) {
                tempOnoise = 
                  Nintegrate(noizDens[i], lnNdens[i],
                             here->HSM1nVar[LNLSTDENS][i], data);
                tempInoise = 
                  Nintegrate(noizDens[i] * data->GainSqInv, 
                             lnNdens[i] + data->lnGainInv,
                             here->HSM1nVar[LNLSTDENS][i] + data->lnGainInv,
                             data);
                here->HSM1nVar[LNLSTDENS][i] = lnNdens[i];
                data->outNoiz += tempOnoise;
                data->inNoise += tempInoise;
                if ( ((NOISEAN*)ckt->CKTcurJob)->NStpsSm != 0 ) {
                  here->HSM1nVar[OUTNOIZ][i] += tempOnoise;
                  here->HSM1nVar[OUTNOIZ][HSM1TOTNOIZ] += tempOnoise;
                  here->HSM1nVar[INNOIZ][i] += tempInoise;
                  here->HSM1nVar[INNOIZ][HSM1TOTNOIZ] += tempInoise;
                }
              }
            }
          }
          if ( data->prtSummary ) {
            for (i = 0; i < HSM1NSRCS; i++) {
              /* print a summary report */
              data->outpVector[data->outNumber++] = noizDens[i];
            }
          }
          break;
        case INT_NOIZ:
          /* already calculated, just output */
          if ( ((NOISEAN*)ckt->CKTcurJob)->NStpsSm != 0 ) {
            for ( i = 0; i < HSM1NSRCS; i++ ) {
              data->outpVector[data->outNumber++] = here->HSM1nVar[OUTNOIZ][i];
              data->outpVector[data->outNumber++] = here->HSM1nVar[INNOIZ][i];
            }
          }
          break;
        }
        break;
      case N_CLOSE:
        /* do nothing, the main calling routine will close */
        return (OK);
        break;   /* the plots */
      }       /* switch (operation) */
    }    /* for here */
  }    /* for model */
  
  return(OK);
}

