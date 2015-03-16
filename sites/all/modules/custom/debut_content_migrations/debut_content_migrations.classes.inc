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
