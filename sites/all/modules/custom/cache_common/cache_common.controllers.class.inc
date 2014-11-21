<?php
/**
 * @file
 * Entity controllers controller.
 */

/**
 * Node controller replacement.
 */
if (class_exists('NodeController')) {
  class CacheCommonNodeController extends NodeController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('node', $entities);

      return $entities;
    }
  }
}

/**
 * Taxonomy term conroller replacement.
 */
if (class_exists('TaxonomyTermController')) {
  class CacheCommonTaxonomyTermController extends TaxonomyTermController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('taxonomy_term', $entities);

      return $entities;
    }
  }
}

/**
 * Commerce product controller.
 */
if (class_exists('CommerceProductEntityController')) {
  class CacheCommonCommerceProductController extends CommerceProductEntityController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('commerce_product', $entities);

      return $entities;
    }
  }
}

/**
 * Asset term conroller replacement.
 */
if (class_exists('EntityAPIController')) {
  class CacheCommonAssetController extends EntityAPIController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('asset', $entities);

      return $entities;
    }
  }
}
