; $Id;

ESI Module
==========

Provides basic and really incomplete ESI support for Drupal.

If no ESI gate is present, you can use this module in downgrade mode. In this
particular mode, each ESI elements will be gracefully replaced by custom AJAX
loading facilities.

Methodology
-----------

 1. Each module that can replace page elements using ESI tags must override
    normal core rendering behavior using its own callbacks, that calls the
    esi_build_tag() function.

 2. This particular function will create the ESI tag (or AJAX placeholder if
    the module is in downgrade mode) and the full Drupal cache may then be
    statically cached as is.

 3. Either the ESI gate or the custom AJAX script will call the esi/%/% menu
    callback, the will call the module specific render callback. Before this
    call, it will aggregate variables reset environment so that the custom
    code can safely use Drupal core API.

Variables
---------

The module provide a variable managing system. Variables may be anything from
the current theme being used ot the user being logged. Implementing modules
can provide their own specific variables at esi_build_tag() call they will
then retrieve when the ESI module rendering callback is being called.

Per default, the ESI module will set correctly session information and full
page theme. Modules can safely use the normal core globals or API to handle
those. Any other business context must be handled by the specific variables.

Caching
-------

This module provide strong ESI elements caching, on server side. Modules can
explicitely disable caching when rendering their custom element.

Rendering is cached using this algorithm:

 1. Without any variables, uses the custom element type and identifier as
    cache identifier.

 2. If variables are provided, the serialized variables array MD5 hash is
    used to compute the cache identifier. To ensure maximum cache hit rate,
    the variables are being sorted by key order before hashed.

Those variables includes all ESI module core variables, which means that
all cached element will be cached using theme and user information. To
provide a global caching instead, you can impose a more specific cache mode
at esi_build_tag() call time.

Creating you own custom module
------------------------------

Right now, no complete documentation is provided, see the esi_block module,
it should give you all the basis for creating custom modules.
