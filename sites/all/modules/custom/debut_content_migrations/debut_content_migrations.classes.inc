<?php
/**
 * @file
 * Migration classes.
 */

class DebutNewsMigration extends Migration{

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migration of the news nodes from old version');

    // Define the field which normally is a primary key.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Node ID',
          'alias' => 'n',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Grab data from tables in source database.
    $query = db_select(SOURCE_DATABASE . '.node', 'n')
      ->fields('n', array('nid', 'vid', 'title', 'uid', 'status'))
      ->condition('n.type', 'news', '=');
    $query->join(SOURCE_DATABASE . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->fields('nr', array('body'));

    // Grab other fields which can mapping directly.
    $query->join(SOURCE_DATABASE . '.content_type_news', 'ct', 'ct.vid = n.vid');
    $query->addField('ct', 'field_news_annonce_value');
    $query->join(SOURCE_DATABASE . '.content_field_publication_date', 'cf', 'cf.vid = n.vid');
    $query->addField('cf', 'field_publication_date_value');
    $query->orderBy('n.nid', 'ASC');

    // Add source fields which not queried in $query, will be populated in prepareRow()
    $source_fields = array(
      'nid' => t('Node id'),
      'title' => t('Node title'),
    );

     // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationNode('news');

    // Mapping: Assign mappings TO destination fields FROM source fields.
    // Simple Mappings : map the fields with the same name.
    $this->addSimpleMappings(array('title', 'nid', 'status'));
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('field_news_annonce', 'field_news_annonce_value');
    $this->addFieldMapping('field_news_annonce:format')->defaultValue('full_html');
    $this->addFieldMapping('field_news_full_text', 'body');
    $this->addFieldMapping('field_news_full_text:format')->defaultValue('full_html');
    $this->addFieldMapping('field_publication_date', 'field_publication_date_value');

  }

  public function prepareRow($row) {
    $row->field_news_annonce_value = htmlspecialchars_decode($row->field_news_annonce_value);
    $row->body = htmlspecialchars_decode($row->body);
  }

}

class DebutPressMigration extends Migration{

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migration of the press nodes from old version');

    // Define the field which normally is a primary key.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Node ID',
          'alias' => 'n',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Grab data from tables in source database.
    $query = db_select(SOURCE_DATABASE . '.node', 'n')
      ->fields('n', array('nid', 'vid', 'title', 'status'))
      ->condition('n.type', 'press_about_debut', '=');
    $query->join(SOURCE_DATABASE . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->fields('nr', array('body'));

    // Grab other fields which can mapping directly.
    $query->join(SOURCE_DATABASE . '.content_type_press_about_debut', 'ct', 'ct.vid = n.vid');
    $query->addField('ct', 'field_press_author_value');
    $query->addField('ct', 'field_press_publication_link_value');
    $query->addField('ct', 'field_press_publication_text_value');
    $query->join(SOURCE_DATABASE . '.content_field_publication_date', 'cf', 'cf.vid = n.vid');
    $query->addField('cf', 'field_publication_date_value');
    $query->orderBy('n.nid', 'ASC');

    // Add source fields which not queried in $query, will be populated in prepareRow()
    $source_fields = array(
      'nid' => t('Node id'),
      'title' => t('Node title'),
    );

     // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationNode('press_about_debut');

    // Mapping: Assign mappings TO destination fields FROM source fields.
    // Simple Mappings : map the fields with the same name.
    $this->addSimpleMappings(array('title', 'nid', 'status'));
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('field_press_author', 'field_press_author_value');
    $this->addFieldMapping('field_press_publication_text', 'field_press_publication_text_value');
    $this->addFieldMapping('field_press_publication_link', 'field_press_publication_link_value');
    $this->addFieldMapping('field_press_text', 'body');
    $this->addFieldMapping('field_press_text:format')->defaultValue('full_html');
    $this->addFieldMapping('field_publication_date', 'field_publication_date_value');

  }

  public function prepareRow($row) {
    $row->body = htmlspecialchars_decode($row->body);
    $row->field_press_author_value = html_entity_decode($row->field_press_author_value);
    $row->field_press_publication_text_value = html_entity_decode($row->field_press_publication_text_value);
  }

}

class DebutVideoMigration extends Migration{

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migration of the video nodes from old version');

    // Define the field which normally is a primary key.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Node ID',
          'alias' => 'n',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Grab data from tables in source database.
    $query = db_select(SOURCE_DATABASE . '.node', 'n')
      ->fields('n', array('nid', 'vid', 'title', 'status'))
      ->condition('n.type', 'video', '=');
    $query->join(SOURCE_DATABASE . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->fields('nr', array('body'));

    // Grab other fields which can mapping directly.
    $query->join(SOURCE_DATABASE . '.content_type_video', 'ct', 'ct.vid = n.vid');
    $query->addField('ct', 'field_video_url_value');
    $query->leftJoin(SOURCE_DATABASE . '.files', 'f', 'ct.field_video_image_fid = f.fid');
    $query->addField('f', 'filename');
    $query->join(SOURCE_DATABASE . '.content_field_publication_date', 'cf', 'cf.vid = n.vid');
    $query->addField('cf', 'field_publication_date_value');
    $query->orderBy('n.nid', 'ASC');

    // Add source fields which not queried in $query, will be populated in prepareRow()
    $source_fields = array(
      'nid' => t('Node id'),
      'title' => t('Node title'),
      'filename' => t('Image filename'),
    );

     // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationNode('video');

    // Mapping: Assign mappings TO destination fields FROM source fields.
    // Simple Mappings : map the fields with the same name.
    $this->addSimpleMappings(array('title', 'nid', 'status'));
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('field_video_url', 'field_video_url_value');
    $this->addFieldMapping('field_video_image');
    //$this->addFieldMapping('field_video_image', 'filename');
    $this->addFieldMapping('field_video_body', 'body');
    $this->addFieldMapping('field_publication_date', 'field_publication_date_value');
    $this->addFieldMapping('field_video_body:format')->defaultValue('full_html');


  }

  public function prepareRow($row) {
    dpm($row->filename);
    $row->body = htmlspecialchars_decode($row->body);
  }

  public function prepare($node, $row) {
     if($row->filename) {
       $file_path='http://www.pokolenie-debut.com/sites/default/files/imagecache/debut_video_push_big/video_images/' . $row->filename;
       $destination='public://video/' . $row->filename;

       $data = drupal_http_request($file_path);
       if($data->code==200){
         $file = file_save_data($data->data, $destination);
         if ($file) {
            $node->field_video_image[LANGUAGE_NONE][] = (array)$file;
            node_save($node);
         }
       }
     }
  }

}

class DebutAlphabetMigration extends Migration{

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migration of the press nodes from old version');

    // Define the field which normally is a primary key.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Term ID',
          'alias' => 'td',
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // Grab data from tables in source database.
    $query = db_select(SOURCE_DATABASE . '.term_data', 'td')
      ->fields('td', array('tid', 'vid', 'name', 'description', 'weight'))
      ->condition('td.vid', 4, '=');


    // Add source fields which not queried in $query, will be populated in prepareRow()
    $source_fields = array(
      'tid' => t('Term id'),
      'name' => t('Term id'),
      'description' => t('Term id'),
      'weight' => t('Term id'),
     );

     // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query);
    $this->destination = new MigrateDestinationTerm('alphabet');

    // Mapping: Assign mappings TO destination fields FROM source fields.
    // Simple Mappings : map the fields with the same name.
    //$this->addFieldMapping('tid', 'tid');
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('description', 'description');
    $this->addFieldMapping('format')->defaultValue('plain_text');
    $this->addFieldMapping('weight', 'weight');

  }

   public function prepareRow($current_row) {
    if ($current_row->parent == 0) {
      unset($current_row->parent);
    }
    return TRUE;
  }

}

class DebutPrizesMigration extends Migration{

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migration of the press nodes from old version');

    // Define the field which normally is a primary key.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'tid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Term ID',
          'alias' => 'td',
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // Grab data from tables in source database.
    $query = db_select(SOURCE_DATABASE . '.term_data', 'td')
      ->fields('td', array('tid', 'vid', 'name', 'description', 'weight'))
      ->condition('td.vid', 3, '=');


    // Add source fields which not queried in $query, will be populated in prepareRow()
    $source_fields = array(
      'tid' => t('Term id'),
     );

     // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationTerm('debut_prizes');

    // Mapping: Assign mappings TO destination fields FROM source fields.
    // Simple Mappings : map the fields with the same name.
    //$this->addFieldMapping('tid', 'tid');
    $this->addFieldMapping('name', 'name');
    $this->addFieldMapping('description', 'description');
    $this->addFieldMapping('format')->defaultValue('plain_text');
    $this->addFieldMapping('weight', 'weight');

  }

}

class DebutPrizePersonsMigration extends Migration{

  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Migration of the debut authors from old version');

    // Define the field which normally is a primary key.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Node ID',
          'alias' => 'n',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Grab data from tables in source database.
    $query = db_select(SOURCE_DATABASE . '.node', 'n')
      ->fields('n', array('nid', 'vid', 'title', 'status'))
      ->condition('n.type', 'debut_prize_person', '=');
    $query->join(SOURCE_DATABASE . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->fields('nr', array('body'));

    // Grab other fields which can mapping directly.
    $query->join(SOURCE_DATABASE . '.content_type_debut_prize_person', 'ct', 'ct.vid = n.vid');
    $query->addField('ct', 'field_person_name_value');
    $query->addField('ct', 'field_person_surname_value');
    $query->addField('ct', 'field_person_info_value');
    $query->addField('ct', 'field_person_biography_value');
    $query->addField('ct', 'field_person_biography_short_value');
    $query->addField('ct', 'field_person_autocomment_value');
    $query->addField('ct', 'field_person_autocomment_short_value');
    $query->addField('ct', 'field_person_resources_value');
    $query->join(SOURCE_DATABASE . '.content_field_person_image', 'cpi', 'cpi.vid = n.vid');
    $query->leftJoin(SOURCE_DATABASE . '.files', 'f', 'cpi.field_person_image_fid = f.fid');
    $query->addField('f', 'filename');
    $query->join(SOURCE_DATABASE . '.content_field_person_awards', 'cfpa', 'cfpa.vid = n.vid');
    $query->addField('cfpa', 'field_person_awards_value');
    $query->orderBy('n.nid', 'ASC');

    // Add source fields which not queried in $query, will be populated in prepareRow()
    $source_fields = array(
      'nid' => t('Node id'),
      'title' => t('Node title'),
      'filename' => t('Image filename'),
    );

     // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationNode('debut_prize_person');

    // Mapping: Assign mappings TO destination fields FROM source fields.
    // Simple Mappings : map the fields with the same name.
    $this->addSimpleMappings(array('title', 'nid', 'status'));
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('field_person_name', 'field_person_name_value');
    $this->addFieldMapping('field_person_surname', 'field_person_surname_value');
    $this->addFieldMapping('field_person_info', 'field_person_info_value');
    $this->addFieldMapping('field_person_autocomment', 'field_person_autocomment_value');
    $this->addFieldMapping('field_person_autocomment_short', 'field_person_autocomment_short_value');
    $this->addFieldMapping('field_person_biography', 'field_person_biography_value');
    $this->addFieldMapping('field_person_biography_short', 'field_person_biography_short_value');
    $this->addFieldMapping('field_person_resources', 'field_person_resources_value');
    $this->addFieldMapping('field_person_image');
    $this->addFieldMapping('field_person_info:format')->defaultValue('full_html');
    $this->addFieldMapping('field_person_autocomment:format')->defaultValue('full_html');
    $this->addFieldMapping('field_person_autocomment_short:format')->defaultValue('full_html');
    $this->addFieldMapping('field_person_biography:format')->defaultValue('full_html');
    $this->addFieldMapping('field_person_biography_short:format')->defaultValue('full_html');
    $this->addFieldMapping('field_person_resources:format')->defaultValue('full_html');
    $this->addFieldMapping('field_person_awards');
  }

  public function prepareRow($row) {
    $row->field_person_info = html_entity_decode($row->field_press_author_value);
    $row->field_person_autocomment = html_entity_decode($row->field_press_author_value);
    $row->field_person_autocomment_short = html_entity_decode($row->field_press_author_value);
    $row->field_person_biography = html_entity_decode($row->field_press_author_value);
    $row->field_person_biography_short = html_entity_decode($row->field_press_author_value);
    $row->field_person_resources = html_entity_decode($row->field_press_author_value);


  }

  public function prepare($node, $row) {
     if($row->filename) {
       $file_path='http://www.pokolenie-debut.com/sites/default/files/imagecache/debut_person_page_photo/writers_images/' . $row->filename;
       $destination='public://writers_images/' . $row->filename;

       $data = drupal_http_request($file_path);
       if($data->code==200){
         $file = file_save_data($data->data, $destination);
         if ($file) {
            $node->field_person_image[LANGUAGE_NONE][] = (array)$file;
            node_save($node);
         }
       }
     }
  }

  public function postImport() {
    $query = db_select(SOURCE_DATABASE . '.node', 'n')
      ->fields('n', array('nid', 'vid', 'title'))
      ->condition('n.type', 'debut_prize_person', '=');
    $query->join(SOURCE_DATABASE . '.content_field_person_awards', 'cfpa', 'cfpa.vid = n.vid');
    $query->addField('cfpa', 'field_person_awards_value');
    $query->orderBy('n.nid', 'ASC');

    $result = $query->execute()->fetchAll();
    foreach ($result as $item) {
      if (!empty($item->field_person_awards_value)) {
        $query = db_select(SOURCE_DATABASE . '.term_data', 'td')
          ->fields('td', array('tid', 'vid', 'name'))
          ->condition('td.tid', $item->field_person_awards_value, '=');
        $term_name = $query->execute()->fetchField(2);
        $tid = array_keys(taxonomy_get_term_by_name($term_name));
        $tid = array_shift($tid);
        $node = node_load ($item->nid);
        $node->field_person_awards[LANGUAGE_NONE][] = array('target_id' => $tid);
        node_save($node);
      }
    }

    $query = db_select(SOURCE_DATABASE . '.node', 'n')
      ->fields('n', array('nid', 'vid', 'title', 'status'))
      ->condition('n.type', 'debut_prize_person', '=');
    $query->join(SOURCE_DATABASE . '.content_field_person_biography_title', 'cfbt', 'cfbt.vid = n.vid');
    $query->addField('cfbt', 'field_person_biography_title_value');
    $query->addField('cfbt', 'delta');
    $query->leftJoin(SOURCE_DATABASE . '.content_field_person_biography_text', 'cfbb', 'cfbb.vid = n.vid AND cfbb.delta=cfbt.delta');
    $query->addField('cfbb', 'field_person_biography_text_value');
    $query->addField('cfbt', 'delta');
    $query->orderBy('n.nid', 'ASC');
    $res = $query->execute()->fetchAll();

    foreach ($res as $item){
    	$collection_item = entity_create('field_collection_item', array('field_name' => 'field_person_bibliography'));

      $host_entity = node_load($item->nid);
      $collection_item->setHostEntity('node', $host_entity);

      $collection_item->field_person_biography_title[LANGUAGE_NONE][0]['value'] = $item->field_person_biography_title_value;
      $collection_item->field_person_biography_text[LANGUAGE_NONE][0]['value'] = $item->field_person_biography_text_value;
      $collection_item->save();
    }
  }

} // end class.
