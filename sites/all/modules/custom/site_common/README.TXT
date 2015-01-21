7.x-0.06
- Async load and JQM scripts improvements (@see file site-common.async-example.js for async example)

7.x-0.5
- jQuery Mobile integration script added

7.x-0.4
- Added environment settings restoration facility, please see site_common.drush.inc file

Example settings.php setings:

// Allow database restoration for local environment.
// THIS SHOULD BE HERE ONLY FOR LOCAL ENVS!
$conf['site_common_allow_db_restore'] = TRUE;

// Block environment from functioning until it is prepared.
// THIS SHOUL BE DIFFERENT FOR EACH USER MACHINE
$conf['site_common_local_environment'] = 'developer_local';

// This is array diff to variable_get('qtools_varnish_settings')
$site_common_env['qtools_varnish']['settings'] = array(
  'general' => array(
    'noise' => '57f6cf9c',
  ),
  'connection' => array(
    'control_terminal' => '192.168.22.134:6082',
    'control_key' => '07fc3efb-d2cc-472e-9208-33f1b0786d13',
  ),
);

// This is values to be submitted to server config, keyed by server name.
$site_common_env['site_common']['search_api'] = array(
  'default_solr_server' => array(
    'host' => 'localhost',
    'port' => '8983',
    'path' => '/solr/mysite',
    'http_user' => '',
    'http_pass' => '',
  ),
);

// Simple list of variables that needs to be updated.
$site_common_env['site_common']['variables'] = array(
  'site_name' => 'mysite.com',
  'site_mail' => 'mail@gmail.com',
  'site_common_current_environment' => $conf['site_common_local_environment'],
);

// Edit array to update user(1) with.
$site_common_env['site_common']['admin'] = array(
  'name' => 'admin',
  'pass' => 'admin',
  'mail' => 'mail@gmail.com',
);

// List of domain records that should be updated.
$site_common_env['site_common']['domain'] = array(
  'machine_name1' => array(
    'subdomain' => 'site1.local.com',
    'sitename' => 'Site1',
  ),
  'machine_name2' => array(
    'subdomain' => 'site2.local.com',
    'sitename' => 'Site2',
  ),
);

// Move our settings to globals.
$GLOBALS['site_common_env'] = $site_common_env;