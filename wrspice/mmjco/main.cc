//==============================================
// Main function for mmjco command loop.
// S. R. Whiteley, wrcad.com,  Synopsys, Inc
//==============================================
//
// License:  GNU General Public License Version 3m 29 June 2007.

#include "mmjco_cmds.h"
#include "mmjco_tscale.h"
#include <stdio.h>


// Generally, mmjco enters a command prompt loop, where the following
// commands are known:
//   cd[ata]
//   cf[it]
//   cm[odel]
//   cs[weep]
//   ct[ab]
//   d[ir]
//   g[ap]
//   ld[ata]
//   lf[it]
//   ls[weep]
//   h[elp]
//   q[uit] | e[xit]
// The remainder of the line contains arguments as expected by the
// functions above.
//
// If the first argument to the mmjco executable is "cdf", a TCA file
// and corresponding fit file are created, and mmfco exits immediately
// in this case.  Arguments following "cdf" are the same arguments
// that can follow the cd and cf interactive commands.  This mode is
// used by the TJM device model in WRspice.
//
// Similarly, "swf" will create a possibly-interpolated fit file from
// an existing sweep file.
//
int main(int argc, char **argv)
{
    mmjco_cmds mmc;
    char buf[256];
    char *av[MAX_ARGC];
    int ac;

    if (argc > 1) {
        if (!strcmp(argv[1], "cdf")) {
            // mmjco cdf [cd and cf arguments]
            if (mmc.mm_create_data(argc-1, argv+1))
                return (1);
            if (mmc.mm_create_fit(argc-1, argv+1))
                return (1);
            return (0);
        }
        if (!strcmp(argv[1], "swf")) {
            // mmjco swf -fs sweepfile temp
            mmjco_mtdb *mt;
            double temp;
            char *swf;
            if (mmc.mm_get_sweep_fit(argc-1, argv+1, &mt, &temp, &swf))
                return (1);
            char *tbf = new char[strlen(swf) + 16];
            strcpy(tbf, swf);
            delete [] swf;
            char *t = strrchr(tbf, '.');
            if (t && !strcmp(t, ".swp"))
                *t = 0;
            sprintf(tbf + strlen(tbf), "_%.4f.fit", temp);
            bool ret = mt->dump_file(tbf);
            delete mt;
            delete [] tbf;
            if (!ret) {
                fprintf(stderr, "Error: write fit file failed.\n");
                return (1);
            }
            return (0);
        }
    }
    for (;;) {
        printf("mmjco> ");
        fflush(stdout);
        char *s = fgets(buf, 256, stdin);
        mmjco_cmds::get_av(av, &ac, s);
        if (ac < 1)
            continue;
        if (av[0][0] == 'c' && av[0][1] == 'd')
            mmc.mm_create_data(ac, av);
        else if (av[0][0] == 'c' && av[0][1] == 'f')
            mmc.mm_create_fit(ac, av);
        else if (av[0][0] == 'c' && av[0][1] == 'm')
            mmc.mm_create_model(ac, av);
        else if (av[0][0] == 'c' && av[0][1] == 's')
            mmc.mm_create_sweep(ac, av);
        else if (av[0][0] == 'c' && av[0][1] == 't')
            mmc.mm_create_table(ac, av);
        else if (av[0][0] == 'd')
            mmc.mm_set_dir(ac, av);
        else if (av[0][0] == 'g')
            mmc.mm_get_gap(ac, av);
        else if (av[0][0] == 'l' && av[0][1] == 'd')
            mmc.mm_load_data(ac, av);
        else if (av[0][0] == 'l' && av[0][1] == 'f')
            mmc.mm_load_fit(ac, av);
        else if (av[0][0] == 'l' && av[0][1] == 's')
            mmc.mm_load_sweep(ac, av);
        else if (av[0][0] == 'q' || av[0][0] == 'e')
            break;
        else if (av[0][0] == 'h' || av[0][0] == 'v' || av[0][0] == '?') {
            printf("mmjco version %s\n", mmjco::version());
            printf(
"cd[ata]  [-t temp] [-d|-d1|-d2 delta] [-s smooth] [-x nx] [-f filename]\\\n"
"         [-r | -rr | -rd]\n"
"    Create TCA data, save internally and to file.\n"
"cf[it]  [-n terms] [-h thr] [-ff filename]\n"
"    Create fit parameters for TCA data, save internally and to file.\n"
"cm[odel]  [-h thr] [-fm [filename]] [-r | -rr | -rd]\n"
"    Create model for TCA data using fitting parameters, compute fit\n"
"    measure, optionally save to file.\n"
"cs[weep] Tstrt Tend [delta] [cd and cf args]\n"
"    Create a temperature sweep file, delta defaults to 0.1K.\n"
"ct[ab] T1 T2 [... TN] [cd and cf args]\n"
"    Create a temperature table file."
"d[ir] directory_path\n"
"    Use the given directory as source and destination for TCA files.\n"
"g[ap] [-tc Tc] [-td Debye] [T1 ...]\n"
"    Compute the superconducting BCS gap at temperature.\n"
"ld[ata] filename\n"
"    Load internal data register from TCA data file.\n"
"lf[it] filename\n"
"    Load internal register from fit parameter file.\n"
"ls[weep] -fs filename temp\n"
"    Load internal register from interpolated fit parameter sweep file.\n"
"h[elp] | v[ersion] | ?\n"
"    Print this help.\n"
"q[uit] | e[xit]\n"
"    Exit mmjco.\n");

        }
        else
            printf("huh? unknown command.\n");
    }
    return (0);
}

