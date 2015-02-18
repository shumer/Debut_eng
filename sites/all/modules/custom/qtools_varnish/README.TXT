7.x-2.07
- ESI pane fixed
- ESI blocks api added
- Varnish considered off on POST requests

7.x-2.06
- User blocks cachemode fixed.

7.x-2.05
- User blocks cache tags fixed.

7.x-2.04
- Support for Panels everywhere added.

7.x-2.03
- Support for Views GET method switch added.
- Support for site_common environment restoration feature
- Avaialbility settings moved to settings page (like enabled for https)
- Ability to purge image/file cache when node updated with same image name.

7.x-2.02
- All outgoing headers contains dashed instead of underscores.

7.x-2.01
- Module name changed to match its content and accompany major innner changes
- Module no longer have dependencies on Varnish or ESI api as those may chnage or will not be ready for
  Drupal 8
- Region cache removed as obsolete but left for reference in qtools_esi module

7.x-1.13
- Added "save to feature" option, disabled for new pages, this option is checked for
  all pages created prior 7.x-1.13.

7.x-1.12 (require qtools 7.x-1.03 or newer)
- Added support for new panels module
- Added ability to set TTL based on page URL for non panels (require deeper testing)
- Added redirect check in hook_init() to see if we can redirect to update cookies (fix redirect loop)
