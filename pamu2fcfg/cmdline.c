/*
  File autogenerated by gengetopt version 2.23
  generated with the following command:
  gengetopt --no-handle-help --input cmdline.ggo Makefile.am 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef FIX_UNUSED
#define FIX_UNUSED(X) (void) (X) /* avoid warnings for unused params */
#endif

#include <getopt.h>

#include "cmdline.h"

const char *gengetopt_args_info_purpose = "Perform a U2F registration operation and print a configuration line that can be\nused with the pam_u2f module.";

const char *gengetopt_args_info_usage = "Usage: " CMDLINE_PARSER_PACKAGE " [OPTION]...";

const char *gengetopt_args_info_versiontext = "";

const char *gengetopt_args_info_description = "";

const char *gengetopt_args_info_help[] = {
  "  -h, --help               Print help and exit",
  "      --version            Print version and exit",
  "  -o, --origin=STRING      Origin URL to use during registration. Defaults to\n                             pam://hostname",
  "  -i, --appid=STRING       Application ID to use during registration. Defaults\n                             to pam://hostname",
  "  -t, --type=STRING        COSE type to use during registration (ES256 or\n                             RS256). Defaults to ES256.",
  "  -r, --resident           Generate a resident credential  (default=off)",
  "  -P, --no-user-presence   Allow the credential to be used without ensuring the\n                             user's presence  (default=off)",
  "  -N, --pin-verification   Require PIN verification during authentication\n                             (default=off)",
  "  -V, --user-verification  Require user verification during authentication\n                             (default=off)",
  "  -d, --debug              Print debug information (highly verbose)\n                             (default=off)",
  "  -v, --verbose            Print information about chosen origin and appid\n                             (default=off)",
  "\n Group: user",
  "  -u, --username=STRING    The name of the user registering the device.\n                             Defaults to the current user name",
  "  -n, --nouser             Print only registration information (keyHandle and\n                             public key). Useful for appending",
    0
};

typedef enum {ARG_NO
  , ARG_FLAG
  , ARG_STRING
} cmdline_parser_arg_type;

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);


static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->origin_given = 0 ;
  args_info->appid_given = 0 ;
  args_info->type_given = 0 ;
  args_info->resident_given = 0 ;
  args_info->no_user_presence_given = 0 ;
  args_info->pin_verification_given = 0 ;
  args_info->user_verification_given = 0 ;
  args_info->debug_given = 0 ;
  args_info->verbose_given = 0 ;
  args_info->username_given = 0 ;
  args_info->nouser_given = 0 ;
  args_info->user_group_counter = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  FIX_UNUSED (args_info);
  args_info->origin_arg = NULL;
  args_info->origin_orig = NULL;
  args_info->appid_arg = NULL;
  args_info->appid_orig = NULL;
  args_info->type_arg = NULL;
  args_info->type_orig = NULL;
  args_info->resident_flag = 0;
  args_info->no_user_presence_flag = 0;
  args_info->pin_verification_flag = 0;
  args_info->user_verification_flag = 0;
  args_info->debug_flag = 0;
  args_info->verbose_flag = 0;
  args_info->username_arg = NULL;
  args_info->username_orig = NULL;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{


  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->origin_help = gengetopt_args_info_help[2] ;
  args_info->appid_help = gengetopt_args_info_help[3] ;
  args_info->type_help = gengetopt_args_info_help[4] ;
  args_info->resident_help = gengetopt_args_info_help[5] ;
  args_info->no_user_presence_help = gengetopt_args_info_help[6] ;
  args_info->pin_verification_help = gengetopt_args_info_help[7] ;
  args_info->user_verification_help = gengetopt_args_info_help[8] ;
  args_info->debug_help = gengetopt_args_info_help[9] ;
  args_info->verbose_help = gengetopt_args_info_help[10] ;
  args_info->username_help = gengetopt_args_info_help[12] ;
  args_info->nouser_help = gengetopt_args_info_help[13] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n",
     (strlen(CMDLINE_PARSER_PACKAGE_NAME) ? CMDLINE_PARSER_PACKAGE_NAME : CMDLINE_PARSER_PACKAGE),
     CMDLINE_PARSER_VERSION);

  if (strlen(gengetopt_args_info_versiontext) > 0)
    printf("\n%s\n", gengetopt_args_info_versiontext);
}

static void print_help_common(void)
{
	size_t len_purpose = strlen(gengetopt_args_info_purpose);
	size_t len_usage = strlen(gengetopt_args_info_usage);

	if (len_usage > 0) {
		printf("%s\n", gengetopt_args_info_usage);
	}
	if (len_purpose > 0) {
		printf("%s\n", gengetopt_args_info_purpose);
	}

	if (len_usage || len_purpose) {
		printf("\n");
	}

	if (strlen(gengetopt_args_info_description) > 0) {
		printf("%s\n\n", gengetopt_args_info_description);
	}
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);
}

void
cmdline_parser_params_init(struct cmdline_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct cmdline_parser_params *
cmdline_parser_params_create(void)
{
  struct cmdline_parser_params *params = 
    (struct cmdline_parser_params *)malloc(sizeof(struct cmdline_parser_params));
  cmdline_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{

  free_string_field (&(args_info->origin_arg));
  free_string_field (&(args_info->origin_orig));
  free_string_field (&(args_info->appid_arg));
  free_string_field (&(args_info->appid_orig));
  free_string_field (&(args_info->type_arg));
  free_string_field (&(args_info->type_orig));
  free_string_field (&(args_info->username_arg));
  free_string_field (&(args_info->username_orig));
  
  

  clear_given (args_info);
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, const char *values[])
{
  FIX_UNUSED (values);
  if (arg) {
    fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
cmdline_parser_dump(FILE *outfile, struct gengetopt_args_info *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", CMDLINE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->origin_given)
    write_into_file(outfile, "origin", args_info->origin_orig, 0);
  if (args_info->appid_given)
    write_into_file(outfile, "appid", args_info->appid_orig, 0);
  if (args_info->type_given)
    write_into_file(outfile, "type", args_info->type_orig, 0);
  if (args_info->resident_given)
    write_into_file(outfile, "resident", 0, 0 );
  if (args_info->no_user_presence_given)
    write_into_file(outfile, "no-user-presence", 0, 0 );
  if (args_info->pin_verification_given)
    write_into_file(outfile, "pin-verification", 0, 0 );
  if (args_info->user_verification_given)
    write_into_file(outfile, "user-verification", 0, 0 );
  if (args_info->debug_given)
    write_into_file(outfile, "debug", 0, 0 );
  if (args_info->verbose_given)
    write_into_file(outfile, "verbose", 0, 0 );
  if (args_info->username_given)
    write_into_file(outfile, "username", args_info->username_orig, 0);
  if (args_info->nouser_given)
    write_into_file(outfile, "nouser", 0, 0 );
  

  i = EXIT_SUCCESS;
  return i;
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = cmdline_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = 0;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

static void
reset_group_user(struct gengetopt_args_info *args_info)
{
  if (! args_info->user_group_counter)
    return;
  
  args_info->username_given = 0 ;
  free_string_field (&(args_info->username_arg));
  free_string_field (&(args_info->username_orig));
  args_info->nouser_given = 0 ;

  args_info->user_group_counter = 0;
}

int
cmdline_parser (int argc, char **argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser_ext (int argc, char **argv, struct gengetopt_args_info *args_info,
                   struct cmdline_parser_params *params)
{
  int result;
  result = cmdline_parser_internal (argc, argv, args_info, params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser2 (int argc, char **argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = cmdline_parser_internal (argc, argv, args_info, &params, 0);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  FIX_UNUSED (args_info);
  FIX_UNUSED (prog_name);
  return EXIT_SUCCESS;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see cmdline_parser_params.check_ambiguity
 * @param override @see cmdline_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, const char *possible_values[],
               const char *default_value,
               cmdline_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  char *stop_char = 0;
  const char *val = value;
  int found;
  char **string_field;
  FIX_UNUSED (field);

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

  FIX_UNUSED (default_value);
    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_FLAG:
    *((int *)field) = !*((int *)field);
    break;
  case ARG_STRING:
    if (val) {
      string_field = (char **)field;
      if (!no_free && *string_field)
        free (*string_field); /* free previous string */
      *string_field = gengetopt_strdup (val);
    }
    break;
  default:
    break;
  };

	FIX_UNUSED(stop_char);
	
  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
  case ARG_FLAG:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


int
cmdline_parser_internal (
  int argc, char **argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error_occurred = 0;
  struct gengetopt_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  /* TODO: Why is this here? It is not used anywhere. */
  override = params->override;
  FIX_UNUSED(override);

  initialize = params->initialize;
  check_required = params->check_required;

  /* TODO: Why is this here? It is not used anywhere. */
  check_ambiguity = params->check_ambiguity;
  FIX_UNUSED(check_ambiguity);

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 0 },
        { "origin",	1, NULL, 'o' },
        { "appid",	1, NULL, 'i' },
        { "type",	1, NULL, 't' },
        { "resident",	0, NULL, 'r' },
        { "no-user-presence",	0, NULL, 'P' },
        { "pin-verification",	0, NULL, 'N' },
        { "user-verification",	0, NULL, 'V' },
        { "debug",	0, NULL, 'd' },
        { "verbose",	0, NULL, 'v' },
        { "username",	1, NULL, 'u' },
        { "nouser",	0, NULL, 'n' },
        { 0,  0, 0, 0 }
      };

      c = getopt_long (argc, argv, "ho:i:t:rPNVdvu:n", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->help_given),
              &(local_args_info.help_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "help", 'h',
              additional_error))
            goto failure;
          cmdline_parser_free (&local_args_info);
          return 0;
        
          break;
        case 'o':	/* Origin URL to use during registration. Defaults to pam://hostname.  */
        
        
          if (update_arg( (void *)&(args_info->origin_arg), 
               &(args_info->origin_orig), &(args_info->origin_given),
              &(local_args_info.origin_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "origin", 'o',
              additional_error))
            goto failure;
        
          break;
        case 'i':	/* Application ID to use during registration. Defaults to pam://hostname.  */
        
        
          if (update_arg( (void *)&(args_info->appid_arg), 
               &(args_info->appid_orig), &(args_info->appid_given),
              &(local_args_info.appid_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "appid", 'i',
              additional_error))
            goto failure;
        
          break;
        case 't':	/* COSE type to use during registration (ES256 or RS256). Defaults to ES256..  */
        
        
          if (update_arg( (void *)&(args_info->type_arg), 
               &(args_info->type_orig), &(args_info->type_given),
              &(local_args_info.type_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "type", 't',
              additional_error))
            goto failure;
        
          break;
        case 'r':	/* Generate a resident credential.  */
        
        
          if (update_arg((void *)&(args_info->resident_flag), 0, &(args_info->resident_given),
              &(local_args_info.resident_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "resident", 'r',
              additional_error))
            goto failure;
        
          break;
        case 'P':	/* Allow the credential to be used without ensuring the user's presence.  */
        
        
          if (update_arg((void *)&(args_info->no_user_presence_flag), 0, &(args_info->no_user_presence_given),
              &(local_args_info.no_user_presence_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "no-user-presence", 'P',
              additional_error))
            goto failure;
        
          break;
        case 'N':	/* Require PIN verification during authentication.  */
        
        
          if (update_arg((void *)&(args_info->pin_verification_flag), 0, &(args_info->pin_verification_given),
              &(local_args_info.pin_verification_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "pin-verification", 'N',
              additional_error))
            goto failure;
        
          break;
        case 'V':	/* Require user verification during authentication.  */
        
        
          if (update_arg((void *)&(args_info->user_verification_flag), 0, &(args_info->user_verification_given),
              &(local_args_info.user_verification_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "user-verification", 'V',
              additional_error))
            goto failure;
        
          break;
        case 'd':	/* Print debug information (highly verbose).  */
        
        
          if (update_arg((void *)&(args_info->debug_flag), 0, &(args_info->debug_given),
              &(local_args_info.debug_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "debug", 'd',
              additional_error))
            goto failure;
        
          break;
        case 'v':	/* Print information about chosen origin and appid.  */
        
        
          if (update_arg((void *)&(args_info->verbose_flag), 0, &(args_info->verbose_given),
              &(local_args_info.verbose_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "verbose", 'v',
              additional_error))
            goto failure;
        
          break;
        case 'u':	/* The name of the user registering the device. Defaults to the current user name.  */
        
          if (args_info->user_group_counter && override)
            reset_group_user (args_info);
          args_info->user_group_counter += 1;
        
          if (update_arg( (void *)&(args_info->username_arg), 
               &(args_info->username_orig), &(args_info->username_given),
              &(local_args_info.username_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "username", 'u',
              additional_error))
            goto failure;
        
          break;
        case 'n':	/* Print only registration information (keyHandle and public key). Useful for appending.  */
        
          if (args_info->user_group_counter && override)
            reset_group_user (args_info);
          args_info->user_group_counter += 1;
        
          if (update_arg( 0 , 
               0 , &(args_info->nouser_given),
              &(local_args_info.nouser_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "nouser", 'n',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
          if (strcmp (long_options[option_index].name, "version") == 0) {
            cmdline_parser_print_version ();
            cmdline_parser_free (&local_args_info);
            exit (EXIT_SUCCESS);
          }

        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */

  if (args_info->user_group_counter > 1)
    {
      fprintf (stderr, "%s: %d options of group user were given. At most one is required%s.\n", argv[0], args_info->user_group_counter, (additional_error ? additional_error : ""));
      error_occurred = 1;
    }
  


	FIX_UNUSED(check_required);

  cmdline_parser_release (&local_args_info);

  if ( error_occurred )
    return (EXIT_FAILURE);

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}
/* vim: set ft=c noet ts=8 sts=8 sw=8 tw=80 nojs spell : */
