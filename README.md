Views Isotope
-------------
Views Isotope is a views style plugin that allows views to return results as jQuery Isotope styled structure.

## Dependencies
* views
* jquery_update
* libraries

## Installation
* Download the [jquery.min.js (1.4.4 or newer)][jquery]
* Place jquery.min.js in sites/all/libraries/jquery/
* Download the latest version of [jquery.isotope.min.js][jquery.isotope]
* Place jquery.isotope.min.js in sites/all/libraries/jquery.isotope/

### Patch jQuery Update module
This module required the use of jQuery 1.4.4, which currently is unsupported in Drupal or jQuery Update (http://drupal.org/node/685060). 

You will need to make the following modifications to the jQuery Update module. Line 166.

Modify the code to look something like this, and replace the arguments with the paths that need jQuery 1.4.4:
<pre>/**
 * Return the path to the jQuery file.
 */
function jquery_update_jquery_path() {
  $jquery_file = array('none' => 'jquery.js', 'min' => 'jquery.min.js');

  if ( arg(0) == 'photos' || arg(0) == 'colours' ) {
    return libraries_get_path('jquery') .'/'. $jquery_file[variable_get('jquery_update_compression_type', 'min')];
  }
  else {
    return JQUERY_UPDATE_REPLACE_PATH .'/'. $jquery_file[variable_get('jquery_update_compression_type', 'min')];
  }
}
</pre>

### Note
This code was build using methods borrowed from [views_cycle][views_cycle]

[jquery]: https://ajax.googleapis.com/ajax/libs/jquery/1.5.0/jquery.min.js
[jquery.isotope]: http://isotope.metafizzy.co/jquery.isotope.min.js
[views_cycle]: http://drupal.org/project/views_cycle